class Solution {
private:
    //LCS Approach 
    int LCS(string& x, string& y)
    {
        //Get the size of the strings
        int m=x.size(),n=y.size();
        //Declare DP
        int dp[m + 1][n + 1];
        //Initialize the first row and column
        for (int i = 0; i < m + 1; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }

        //Fill the dp table
        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                //If the characters are equal take its ASCII value
                if (x[i - 1] == y[j - 1])
                    dp[i][j] = x[i-1] + dp[i - 1][j - 1];
                //Else take the maximum from the previous values
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        //Return the largest value
        return dp[m][n];
    }
public:
    int minimumDeleteSum(string s1, string s2) 
    {
        //Get the longest common subsequence with largest ASCII value
        int stay=LCS(s1,s2);
        int total=0;
        
        //Calculate the total of all the characters in the string
        for(auto it: s1)
            total+=it;
        
        for(auto it: s2)
            total+=it;

        //Return the deleted characters sum
        return total - 2*stay;
        
    }
};
