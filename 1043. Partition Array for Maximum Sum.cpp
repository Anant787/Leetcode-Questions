class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, 0);

        // For every index, we take a subarray of length upto k and find the max element in the subarray.
        // The sum of that sub array becomes equal to the length of the subarray * currMaxSum
        for(int start=n-1; start >= 0; start--){
            int currMax = 0;
            int end = min(n, start+k);
            for(int i=start; i<end; i++){
                currMax = max(currMax, arr[i]);
                dp[start] = max(dp[start], dp[i+1] + currMax*(i-start+1));
            }
        }
        return dp[0];
    }
};
