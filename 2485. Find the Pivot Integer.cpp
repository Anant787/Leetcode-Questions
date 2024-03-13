class Solution {
public:
    int pivotInteger(int n) {
        
    
        vector<int> prefixSum(n + 1, 0);
        int totalSum = 0;

        for (int i = 1; i <= n; i++) {
            totalSum += i;
            prefixSum[i] = totalSum;
        }

        for (int j = 1; j <= n; j++) {
            if (prefixSum[j - 1] == totalSum - prefixSum[j]) {
                return j;
            }
        }
        return -1;
    }
};
