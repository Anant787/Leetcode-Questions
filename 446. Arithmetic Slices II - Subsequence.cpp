class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans =0;
        int n = nums.size();

        vector<unordered_map<int,int>>dp(n);   //dp[i][diff][frequency]
        for(int i =0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                long d = (long)nums[i] - (long)nums[j];   //difference
                if(d<INT_MIN || d>INT_MAX)               // check the boundary case
                {
                    continue;
                }

                dp[i][d]++;          //increment for length 2 

                if(!dp[j].count(d))      
                {
                    continue;
                }

                ans+=dp[j][d];  //ans will be incremented by dp[j][d] as we want the length of subsequenece
                dp[i][d] += dp[j][d]; //increment the count of arthim. slice
            }
        }
        
        return ans;
        
    }
};
