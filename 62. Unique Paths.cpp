class Solution {
public:
    //Same Previous Submission code  Striver Approach
   int uniquePathso(vector<vector<int>>&dp , int i, int j ,int m, int n) {
      
        if(i>=m || j>=n)
        {
            return 0;
        }
         if(i==m-1 && j==n-1)
        {
            return 1;
        }
       if(dp[i][j]!=-1)
       {
           return dp[i][j];
       }
        else return dp[i][j] = uniquePathso(dp, i+1,j,m,n) + uniquePathso(dp,i,j+1,m,n);
    }
    
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>>dp(m, vector<int>(n,-1));
        int i=0,j=0;
       return uniquePathso(dp,i,j,m,n); 
    }
};
