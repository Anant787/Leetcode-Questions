class Solution {
public:
    //Dynamic Programming
    bool f(int i,vector<int>&nums,vector<int>&dp){
        if(i>=nums.size())return true;
        if(dp[i]!=-1)return dp[i];
        //The stuff
        if(i<nums.size()-1&&nums[i]==nums[i+1]&&f(i+2,nums,dp))return true;
        else if(i<nums.size()-2&&nums[i]==nums[i+1]&&nums[i]==nums[i+2]&&f(i+3,nums,dp))return true;
        else if(i<nums.size()-2&&nums[i]==nums[i+1]-1&&nums[i+1]==nums[i+2]-1&&f(i+3,nums,dp))return true;
        return dp[i]=false;
    }
    bool validPartition(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return f(0,nums,dp);
    }
};
