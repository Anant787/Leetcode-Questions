#define MOD 1000000007
class Solution {
public: 
    //DP memoization 
    int countPathsH(vector<vector<int>> &grid, int x, int y, vector<vector<int>>& dp)
{
    if(dp[x][y]!=-1){
        return dp[x][y];
    }
    int current = grid[x][y];
    int ans = 1;
    if (x > 0 && current < grid[x - 1][y])
    {
        ans += countPathsH(grid, x - 1, y, dp)%MOD;
    }
    if (x < grid.size() - 1 && current < grid[x + 1][y])
    {
        ans += countPathsH(grid, x + 1, y, dp)%MOD;
    }
    if (y < grid[0].size() - 1 && current < grid[x][y + 1])
    {
        ans += countPathsH(grid, x, y + 1, dp)%MOD;
    }
    if (y > 0 && current < grid[x][y - 1])
    {
        ans += countPathsH(grid, x, y - 1, dp)%MOD;
    }

    dp[x][y] = ans%MOD;
    return dp[x][y]%MOD;
}

int countPaths(vector<vector<int>> &grid)
{
    vector<vector<int>> dp (grid.size(), vector<int> (grid[0].size(), -1));
    int ans = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            ans = ((ans)%MOD + (countPathsH(grid, i, j, dp))%MOD)%MOD;
        }
    }
    return ans%MOD;
}
};
