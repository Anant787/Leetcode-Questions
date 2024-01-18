class Solution {
public:
    int climbStairs(int n) {
        // if(n<=2)return n;
        
        // int climb1=2,climb2=1,res;
        
        // for(int i=3;i<=n;i++)
        // {
        //     res=climb1+climb2;
        //     climb2=climb1;
        //     climb1=res;
        // }
        // return res;

        // return climbStairs(n-1) + climbStairs(n-2);     TLE  

        // Dp approach   
        
        vector<int>dp(n+1);
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2;i<n+1;i++)
        {
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
        


    }
};
