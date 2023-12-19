class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m = img[0].size();
        
        vector<vector<int>> result(n, vector<int> (m));

         vector<int> row = {-1, 1, 0, 0, -1, 1, 1, -1};
         vector<int> col = {0, 0, -1, 1, -1, -1, 1, 1};

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                 int sum = img[i][j], ct = 1;
                
                 for (int k = 0; k < 8; k++)
                 {
                     int dx = i + row[k];
                     int dy = j + col[k];

                     if (dx >= 0 and dx < n and dy >= 0 and dy < m)
                     {
                         ct++;
                         sum += img[dx][dy];
                     }
                 }
                
                 result[i][j] = sum / ct;
            }
        }

        return result;
    }
};
