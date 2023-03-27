class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>dp(m,vector<int>(n,0)); //Adjacent grid

        dp[0][0] = grid[0][0];  //insert first element

        for(int i=1;i<m;i++)  //mark the element in first row
        {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }

        for(int i=1;i<n;i++)  //mark the element in first column
        {
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }

        //insert the minimum element from left to right in the dp matix
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                dp[i][j] = min(dp[i-1][j] , dp[i][j-1]) + grid[i][j];
            }
        }

        return dp[m-1][n-1];   //return the last element
         
    }
};
