class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int result = 0;  // to store the result
        
        for (int i = 1; i < m; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
                matrix[i][j] = (matrix[i][j] == 1) ? matrix[i-1][j] + 1 : 0;
            }
        }
        for (int i = 0; i < m; ++i) 
        {
            sort(matrix[i].begin(), matrix[i].end());
        }

        for (int i = m - 1; i >= 0; --i) 
        {
            for (int j = 0; j < n; ++j) 
            {
                result = max(result, matrix[i][j] * (n - j));
            }
        }

        return result;
    }
};
