class Solution {
public:
    const int MOD = 1000000007;
    
    int dp[100001][2][3];

    int helper(int indx,int a,int l,int n) {
        if(indx == n) {
            return 1;
        }

        if(dp[indx][a][l] != -1) {
            return dp[indx][a][l];
        }

        int ans = 0;

        ans = (ans+helper(indx+1,a,0,n))%MOD;

        if(a<1) {
            ans = (ans + helper(indx+1,a+1,0,n))%MOD;
        }

        if(l<2) {
            ans = (ans + helper(indx+1,a,l+1,n))%MOD;
        }

        return dp[indx][a][l] = ans;
    }

    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));
        return helper(0,0,0,n)%MOD;
    }
};
