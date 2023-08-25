class Solution {
public:
    //DP Solution
    bool helper(string &s1, string &s2, string &s3,vector<vector<int>> &dp, int i=0, int j=0, int k=0){
        if(i == s1.size() && j == s2.size() && k == s3.size()) return true;
        if(dp[i][j] != -1) return dp[i][j];
        bool ans1 = false;
        bool ans2 = false;

        if(i != s1.size() && s1[i] == s3[k])
            ans1 = helper(s1, s2, s3,dp, i+1, j, k+1);

        if(j != s2.size() && s2[j] == s3[k])
            ans2 = helper(s1, s2, s3,dp, i, j+1, k+1);

        return dp[i][j] = ans1 || ans2;
    }
    bool isInterleave(string s1 ,string  s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return helper(s1, s2, s3, dp);
    }
};
