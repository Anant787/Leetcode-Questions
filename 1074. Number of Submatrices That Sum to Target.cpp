class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) 
    {
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m; i++)
            for(int j = 1; j < n; j++)
                matrix[i][j] += matrix[i][j - 1];

        int count = 0;
        for(int c1 = 0; c1 < n; c1++)
        {
            for(int c2 = c1; c2 < n; c2++)
            {
                int sum = 0;
                unordered_map<int, int>hash;
                hash[0] = 1;
                for(int i = 0; i < m; i++)
                {
                    sum += matrix[i][c2] - (c1 != 0 ? matrix[i][c1 - 1] : 0);
                    if(hash.find(sum - target) != hash.end())
                        count += hash[sum - target];
                    hash[sum] += 1;
                }
            }
        }
        return count;
    }
};
