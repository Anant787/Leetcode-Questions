class Solution {
public:
    //DP
    int solve(vector<int>&prices,int fee,int i,int n,int buy,vector<vector<int>>&dp){
        if(i==n && buy==false) return -1e9;
        if(i==n) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy==1){
            return dp[i][buy]=max(-prices[i]+solve(prices,fee,i+1,n,0,dp),solve(prices,fee,i+1,n,1,dp));
        }
        return dp[i][buy]=max(prices[i]-fee+solve(prices,fee,i+1,n,1,dp),solve(prices,fee,i+1,n,0,dp));
        
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
        return solve(prices,fee,0,prices.size(),1,dp);
    }
};
