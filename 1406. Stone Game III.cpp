class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> dp(n + 1, INT_MIN);      //DP

        dp[n] = 0;  // Base case: no stones remaining, score difference is 0

        for (int i = n - 1; i >= 0; i--)   //iterate from back
        {
            int maxScore = INT_MIN;
            int currSum = 0;

            for (int j = i; j < min(i + 3, n); j++)
            {
                currSum += stoneValue[j];
                maxScore = max(maxScore, currSum - dp[j + 1]);
            }

            dp[i] = maxScore;
        }

        int scoreDiff = dp[0];

        if (scoreDiff > 0) {
            return "Alice";
        } else if (scoreDiff < 0) {
            return "Bob";
        } else {
            return "Tie";
        }
    }
};
