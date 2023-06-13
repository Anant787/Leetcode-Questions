class Solution {
public:
// bool check(vector<vector<int>>& grid,int m,int n){
//         int i=0;int j=0;
//         while(i<grid.size()){
//             if(grid[i][m]!=grid[n][j]){return false;}
//             i++;j++;
//         }
//         return true;
//     }
    int equalPairs(vector<vector<int>>& grid) {
        // int n=grid.size();int cnt=0;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(check(grid,i,j)){cnt++;}
        //     }
        // }
        // return cnt;



        int n = grid.size();
        vector<vector<int>> reverse(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                reverse[j][i] = grid[i][j];
        }
        
        int ans = 0;
        for(auto it: grid){
            for(auto x: reverse)
                if(it == x)
                    ans++;
        }
        return ans;
        
    }
};
