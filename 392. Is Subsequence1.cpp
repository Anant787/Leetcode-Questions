class Solution {
    
    int LCS(string s,string t,int m,int n)
    {
        int d[m+1][n+1];
        
        int i,j;
        
        for(i=0;i<=m;i++)
        {
            for(j=0;j<=n;j++)
            {
                if(i==0 || j==0)
                {
                    d[i][j]=0;
                }
                else if(s[i-1]  == t[j-1])
                {
                    d[i][j] = 1 + d[i-1][j-1];
                }
                else
                {
                    d[i][j] = max(d[i-1][j] , d[i][j-1]);
                }
            }
        }
        return d[m][n];
    }
public:
    bool isSubsequence(string s, string t) {
        
        int m = s.length();
        int n = t.length();
        
        int lcs = LCS(s,t,m,n);
        
        if(lcs == s.length())         //only this conditon with LCS
        {
            return true;
        }
        else
        {
           return false;
        }
        
        
    }
};
