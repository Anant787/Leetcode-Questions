class Solution {
private:
    const int MOD = 1e9+7;
    int add(int a, int b){
        a += b;
        if(a >= MOD) a -= MOD;
        return a;
    }
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m = group.size();
        vector<vector<int>> dp(minProfit+1, vector<int>(n+1, 0));  //vector
        int cnt, pr, res = 0;
        dp[0][0] = 1;
        for(int i = 0; i<m; i++){
            cnt = group[i];
            pr = profit[i];
            //knapscak problem
            for(int j = minProfit; j >= 0; j--){
                for(int k = n - cnt; k >= 0; k--){
                    dp[min(pr+j, minProfit)][cnt+k] = add(dp[min(pr+j, minProfit)][cnt+k], dp[j][k]);
                }
            }
        }
        for(int i = 0; i<=n; i++) res = add(res, dp[minProfit][i]);
        return res;
    }
};
