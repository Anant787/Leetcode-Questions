class Solution {
public:
    // Striver Approach

    int solve(int ind , int prev_ind ,vector<int>&nums,int n , vector<vector<int>>&dp)
    {
        if(ind == n)
        {
            return 0;
        }
        if(dp[ind][prev_ind+1] != -1)
        {
            return dp[ind][prev_ind + 1];
        }
        int len = 0 + solve(ind+1,prev_ind,nums,n,dp);  //not including case

        if(prev_ind == -1 || nums[ind] > nums[prev_ind])  //including case 
        {
            len = max(len , 1 + solve(ind+1,ind,nums,n,dp));// find rhe max between them
        }

        return dp[ind][prev_ind+1] = len;
    }

    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));

        return solve(0,-1,nums,n,dp);
        
    }
};
