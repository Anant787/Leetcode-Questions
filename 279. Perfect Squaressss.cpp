class Solution {
public:
    // int solve(int n)   // simple naive approach
    // {
    //     if(n==0)
    //     {
    //         return 0;
    //     }
    //     int ans = n ;  // ans alloted to maximum value;
        
    //     for(int i=1;i*i<=n;i++)
    //     {
    //         int temp = i*i;
    //         ans = min(ans, 1 + solve(n - temp));
    //     }

    //     return ans;
    // }
    
    // Dynamic Approach Memoization

    int solveMemo(int n ,vector<int>&dp)
    {
        //base case
        if(n == 0)
        {
            return 0;
        }

        if(dp[n] != -1)
        {
            return dp[n];
        }
        
        int ans = INT_MAX; 

        for(int i=1;i*i<=n;i++)
        {
            int temp = i*i;
            ans = min(ans , 1 + solveMemo(n-temp,dp));
        }
        dp[n] = ans;
        return dp[n];
    }

    // int solveTab(int n)       // tabulation method
    // {
    //     vector<int>dp(n+1,INT_MAX);
    //     dp[0] = 0;

    //     for(int i=1;i<=n;i++)
    //     {
    //         for(int j = 1;j*j<=n;j++)
    //         {
    //             int temp = j*j;
    //             if(i-temp >= 0)
    //             {
    //                 dp[i] = min(dp[i] , 1 + dp[i-temp]);
    //             }
    //         }
    //     }
    //     return dp[n];
    // }
    int numSquares(int n) {
        //return solve(n);             // for naive approach 

        vector<int>dp(n+1,-1);        // for dynamic Approach
        return solveMemo(n,dp);

        //return solveTab(n);             // for tabulation method
    }
};
