class Solution {
public:
    const int MOD = 1000000007;       //mod 1e9

    int util(int n, int m, int k, int maxVal, int memo[51][51][101]){
        if(n == 0 && k == 0) return 1;
        if(n == 0 || k < 0) return 0;

        if(memo[n][k][maxVal] != -1) return memo[n][k][maxVal];
        long res = 0;

        for(int i=1; i<=m; ++i){
            
            if(i > maxVal)
                res += util(n-1, m, k-1, i, memo); // Next element increasing
            else       
                res += util(n-1, m, k, maxVal, memo); // Next element not increasing
        }

        return memo[n][k][maxVal] = res % MOD;
    }

    int numOfArrays(int n, int m, int k) {
        int memo[51][51][101];                      //3D DP
        for(int i=0; i<=50; ++i)
            for(int j=0; j<=50; ++j)
                for(int k=0; k<=100; ++k)
                    memo[i][j][k] = -1;
    
        return util(n, m, k, 0, memo);
    }
};
