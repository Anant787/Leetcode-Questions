class Solution {
    
    bool ispalindrome(string& s,int i,int j)
    {
        //if(i==j || i>j)return true;
        
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++ , j--;
        }
        return true;
    }
    
    int solve(string &s,int i,int j,vector<int>&dp)
    {
        if(i>=j || ispalindrome(s,i,j))
        {
            return 0;
        }
        
        if(dp[i] != -1)
        {
            return dp[i];
        }
        
        int mn = INT_MAX;
        int left,right;
        
        for(int k=i ; k<j ;k++)
        {
            
//             if(dp[i][k] != -1)
//             {
//                 left = dp[i][k];
//             }
//             else
//             {
//                 left = solve(s,i,k);
//                 dp[i][k] = left;
//             }
            
//             if(dp[k+1][j] != -1)
//             {
//                 right = dp[k+1][j];
//             }
//             else
//             {
//                 right = solve(s,k+1,j);
//                 dp[k][j] = right;
//             }
            
            if(ispalindrome(s,i,k))
            {
                int temp = 1 + solve(s,k+1,j,dp);
                mn = min(mn,temp);
            }
        }
        return dp[i]=mn;
    }
public:
    int minCut(string s) {
        int n = s.size();
        
        // int static t[2001][2001];
        // memset(t,-1,sizeof(t));  
        
        vector<int>dp(n+1,-1);           //size,element
        
        return solve(s,0,n-1,dp);
    }
};