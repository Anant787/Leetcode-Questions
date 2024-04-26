class Solution {
public:
    int solve(vector<vector<int>>& grid,int n,int m,int i,int j,vector<vector<int>>& dp){
        if(i<0||j>=m||j<0)return 1e9;
        if(i==0)return grid[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        int temp=1e9;
       for(int k=0;k<n;k++){
        if(k==j)continue;
        temp=min(temp,grid[i][j]+ solve(grid, n, m, i - 1, k, dp));
       }
        return dp[i][j]=temp;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=1e9;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<m;i++){
            int cur=solve(grid,n,m,n-1,i,dp);
            ans=min(ans,cur);
        }
        return ans;
    }
};
