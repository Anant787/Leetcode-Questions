class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>>ans(n,vector<int>(n,0));

        int startingRow = 0;
        int endingRow = n-1;
        int startingCol = 0 ;
        int endingCol = n-1 ; 
        int total = n*n;          //size of matrix
        int count = 1;         //take a counter variable

        while(count <= total)
        {
            //left to right
            for(int i = startingCol; i<= endingCol && count<=total ; i++ )
            {
                ans[startingRow][i] = count;
                count++;
            }
            startingRow++;   //not include again
            //top to bottom
            for(int i = startingRow; i<= endingRow && count<=total ; i++ )
            {
                ans[i][endingCol] = count;
                count++;
            }
            endingCol--;

            //right to left

            for(int i = endingCol; i>= startingCol && count<=total ; i-- )
            {
                ans[endingRow][i] = count;
                count++;
            }
            endingRow -- ;

            //bottom to top

            for(int i = endingRow; i>= startingRow && count<=total ; i-- )
            {
                ans[i][startingCol] = count;
                count++;
            }
            startingCol++;

        }

        return ans;
        
    }
};
