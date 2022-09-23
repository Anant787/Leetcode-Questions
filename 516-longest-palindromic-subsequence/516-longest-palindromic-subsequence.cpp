class Solution {
    int LPS(string s)
    {
        string s1 = s;
        
        reverse(s1.begin(),s1.end());
        
        int m = s.size(); 
        int n = s1.size(); 
        
        int t[m+1][n+1];
        int i,j;
        
        for(i=0;i<=m;i++)
        {
            for(j=0;j<=n;j++)
            {
                if(i==0  || j==0)
                {
                    t[i][j]=0;
                }
                else if(s[i-1] == s1[j-1])
                {
                    t[i][j] = 1 + t[i-1][j-1]; 
                }
                else
                {
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        return t[m][n];
    }
    
public:
    int longestPalindromeSubseq(string s) {        
//         string  b = s;
//         reverse(b.begin(),b.end());
        
//         int m = s.size();
//         int n = b.size();
        
//         int lps = LPS(s,b,m,n) ;
        
        return  LPS(s);
              
    }
};