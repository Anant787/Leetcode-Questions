class Solution {
public:
    int integerBreak(int n) {
        // Dp approach 

        if(n<=3)      //for n = 2 and 3 the output is 1 and 2 respectively.
        {
            return n-1;
        }

        vector<int>dp(n+1,0);
        dp[2] = 2;
        dp[3] = 3;

        for(int i = 4;i<=n;i++)
        {
            dp[i] = max(2 * dp[i-2] , 3 * dp[i-3]);
        }

        return dp[n];

        //Basic math approach 

        // if(n<=3) return n-1;
        // int ans = 1;
        // if(n%3==0){
        //     return pow(3,n/3);
        // }else if(n%3==1){
        //     return pow(3,((n/3)-1))*4;
        // }
        // return pow(3,(n/3))*2;
    }
};
