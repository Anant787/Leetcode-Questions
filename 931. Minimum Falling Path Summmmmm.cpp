class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<int> dp = matrix[0];
        
        int ans = INT_MAX;
        for (int r = 1; r < dp.size(); r++) {
            vector<int> sol = dp;
            sol[0] = matrix[r][0] + min({dp[0], dp[1]});
            
            for (int c = 1; c < matrix[r].size() - 1; c++) 
                sol[c] = matrix[r][c] + min({dp[c], dp[c - 1], dp[c + 1]});
            
            int lc = dp.size() - 1;
            sol[lc] = matrix[r][lc] + min({dp[lc], dp[lc - 1]});
            
            dp = sol;
        }
        
        ans = *min_element(dp.begin(), dp.end());
        return ans;
        
    }
};
