class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int n = pizza.size();
        int m = pizza[0].size();
        int mod = 1e9+7;
        vector<vector<int>> apples(n,vector<int>(m)),dp(n,vector<int>(m));
        // Filling apple dp from bottom to up showing how many apples in rectangle [i][j] to [n][m]
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                //check the edge case
                
                int a = (i<n-1) ? apples[i+1][j] : 0;
                int b = (j<m-1) ? apples[i][j+1] : 0;
                int c = (i<n-1 and j<m-1) ? apples[i+1][j+1] : 0;
                int d = (pizza[i][j] == 'A') ? 1 : 0;

                apples[i][j] = a+b-c+d;
                if(apples[i][j]>0) dp[i][j]=1;
            }
        }
        for(int K=1;K<k;K++){
            vector<vector<int>> temp(n,vector<int>(m));
            for(int i=n-1;i>=0;i--){
                for(int j=m-1;j>=0;j--){
                    // If cut vertically 
                    for(int newj = j+1;newj<m;newj++){
                        if(apples[i][j] > apples[i][newj] and dp[i][newj]>0){
                            temp[i][j] = (temp[i][j]+dp[i][newj])%mod;
                        }
                    }
                    // If cut horizontally
                    for(int newi = i+1;newi<n;newi++){
                        if(apples[i][j] > apples[newi][j] and dp[newi][j]>0){
                            temp[i][j] = (temp[i][j] + dp[newi][j])%mod;
                        }
                    }
                }
            }
            dp = temp;
        }
        return dp[0][0];
        
    }
};
