class Solution {
private:
    int helper(int i,int j1,int j2,vector<vector<int>>& grid,vector<vector<vector<int>>> &dp){
        if(j1<0 || j2<0 || j1>=grid[0].size() || j2>=grid[0].size())
            return 0;

        if(i==grid.size()) return 0;

        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int res = grid[i][j1]+grid[i][j2];
        int maxi = 0;

        for(int x1=j1-1;x1<=j1+1;x1++){
            for(int x2=j2-1;x2<=j2+1;x2++){
                if(x1<x2){
                    maxi = max(maxi,helper(i+1,x1,x2,grid,dp));
                }
            }
        }
        res += maxi;
        return dp[i][j1][j2] = res;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(),m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1))); 
        return helper(0,0,m-1,grid,dp);
    }
};
