class Solution {
public:
    int LCS(string X, string Y,int m,int n)
    {
        int t[m+1][n+1];

        for(int i=0;i<m+1;i++)
        {
            for(int j =0;j<n+1;j++)
            {
                if(i==0 || j==0)
                {
                    t[i][j] = 0;
                }
                else if(X[i-1] == Y[j-1])
                {
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else
                {
                    t[i][j] = max(t[i-1][j] , t[i][j-1]);
                }
            }
        }
        return t[m][n];
    }

    int longestCommonSubsequence(string X, string Y) {
        int m = X.size();
        int n = Y.size();

        return LCS(X,Y,m,n);
        
    }
};
