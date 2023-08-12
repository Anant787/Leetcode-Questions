class Solution {
public:
    int solve(int x, int y,vector<vector<int>> &grid,vector<vector<int>> &dp)
    {
        if(grid[x][y]==1)
        {
            return 0;
        }
        if(x==0 and y==0)
        {
            return 1;
        }
        if(dp[x][y]!=-1)
        {
            return dp[x][y];
        }
        int right = 0;
        int down = 0;
        
        if(y>0)
        {
            right=solve(x,y-1,grid,dp);
        }
        if(x>0)
        {
            down=solve(x-1,y,grid,dp);
        }
        
        return dp[x][y]=right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int> > dp(m,vector<int> (n,-1));
        
        return solve(m-1,n-1,grid,dp);
    }
};
