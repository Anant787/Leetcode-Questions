class Solution {
public:
    //DP Solution
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int ans = 1,maxi = 1;
        vector<int> dp(n+1,1),count(n+1,1);

        for(int i =1;i<n;i++){
            for(int j = 0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(dp[j]+1 == dp[i]){
                        count[i]+=count[j];
                    }else if(dp[j]+1 > dp[i]){
                        count[i] = count[j];
                        dp[i] = dp[j]+1;
                    }
                }
            }

            if(dp[i] == maxi){
                ans+=count[i];
            }else if(dp[i] > maxi){
                maxi = dp[i];
                ans = count[i];
            }
        }

        return ans;
    }
};
