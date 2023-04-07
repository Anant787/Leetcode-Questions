class Solution {
public:

    void dfs(vector<vector<int>>& grid,int i,int j,int n,int m){
    
        grid[i][j]=0;

        if(i+1<n && grid[i+1][j]==1) dfs(grid,i+1,j,n,m);

        if(i-1>=0 && grid[i-1][j]==1) dfs(grid,i-1,j,n,m);
        
        if(j+1<m && grid[i][j+1]==1) dfs(grid,i,j+1,n,m);
        
        if(j-1>=0 && grid[i][j-1]==1) dfs(grid,i,j-1,n,m);

}
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        for(int j=0;j<m;j++){
            if(grid[0][j]==1) dfs(grid,0,j,n,m);
        }
        for(int j=0;j<m;j++){
            if(grid[n-1][j]==1) dfs(grid,n-1,j,n,m);
        }
        for(int i=0;i<n;i++){
            if(grid[i][0]==1) dfs(grid,i,0,n,m);
        }
        for(int i=0;i<n;i++){
            if(grid[i][m-1]==1) dfs(grid,i,m-1,n,m);
        }

       int counter=0;

        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(grid[i][j]==1) {
                    
                    counter++;
                }
            }
        }

        return counter;
    }

    // void countEnclaves(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j, int& flag, int& num)
    // {
    //     int n = grid.size();
    //     int m = grid[0].size();
    //     if(!(i >= 0 && i < n && j >=0 && j < m))
    //         return;

    //     if(visited[i][j] == 0)
    //         return;
    //     else
    //         visited[i][j] = 0;  

    //     if((i == 0 || j == 0 || i == n-1 || j == m-1))
    //         flag = 1;
            
    //     num++;
    //     countEnclaves(grid, visited, i + 1, j, flag, num);
    //     countEnclaves(grid, visited, i, j + 1, flag, num);
    //     countEnclaves(grid, visited, i - 1, j, flag, num);
    //     countEnclaves(grid, visited, i, j - 1, flag, num);
    // }
    // int numEnclaves(vector<vector<int>>& grid) {
    //     int n = grid.size();
    //     int m = grid[0].size();
    //     vector<vector<int>> visited = grid;
    //     int count = 0;
    //     for(int i = 0; i < n; i++)
    //     {
    //         for(int j = 0; j < m; j++)
    //         {
    //             if(visited[i][j])
    //             {
    //                 int flag = 0;
    //                 int num = 0;
    //                 countEnclaves(grid, visited, i, j, flag, num);
    //                 if(flag == 0)
    //                     count += num;
    //             }
    //         }
    //     }
    //     return count;
    // }
};
