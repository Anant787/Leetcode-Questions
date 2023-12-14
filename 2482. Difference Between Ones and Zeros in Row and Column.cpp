class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<int>col(m,0);
        vector<int>row(n,0);
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                 if(grid[i][j]==1){
                     col[i]++;
                     row[j]++;
                 }
            }
        }

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int onesCol = col[i];
                int onesRow = row[j];

                int zerosCol = m-onesCol;
                int zerosRow = n-onesRow;
                
                grid[i][j] = onesRow + onesCol - zerosRow - zerosCol;
            }
        }
        return grid;

    }
};
