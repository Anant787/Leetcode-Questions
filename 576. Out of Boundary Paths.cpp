class Solution {
public:
  
 int mod=1e9+7;
 int dp[51][51][51];
   long long  f(int i,int j,int maxi,int n,int m)
   {
       if(maxi<0) return 0;
       if(maxi>=0){
           if(i>=n || j>=m || i<0 || j<0) return 1;
        }

        if(dp[i][j][maxi]!=-1) return dp[i][j][maxi];

      return dp[i][j][maxi]=(f(i+1,j,maxi-1,n,m)+ f(i-1,j,maxi-1,n,m)+f(i,j+1,maxi-1,n,m)+f(i,j-1,maxi-1,n,m))%mod;
   }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp)); 
        long long ans=f(startRow,startColumn,maxMove,m,n);
        return ans%mod;
    }
};
