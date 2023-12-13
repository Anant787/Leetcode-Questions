class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        // //calulate size of row and col
        // int noOfRow = mat.size();
        // int noOfCol = mat[0].size();
        // int count=0;
        
        // //create two variables to keep count of 1s in rows and columns 
        // vector<int> rowCount(noOfRow,0);
        // vector<int> colCount(noOfCol,0);

        // //precompute rows and columns 1s count values
        // for(int row=0;row<noOfRow;row++){
        //     for(int col=0;col<noOfCol;col++){
        //         if(mat[row][col]==1)
        //         { 
        //             rowCount[row]++;
        //             colCount[col]++;
        //         }
        //     }
        // } 

        // //find the best row and col
        // for(int row=0;row<noOfRow;row++){
        //     for(int col=0;col<noOfCol;col++){
        //         if(mat[row][col]==1)
        //         { 
        //             if(rowCount[row]==1 && colCount[col]==1){
        //                 count++;
        //             }
        //         }
        //     }
        // } 

        // return count;

        int ans = 0;
        // first checking each row one by one
        for (int i = 0; i < mat.size(); i++){
            int one = 0;
            int colIndx = -1;
            int zerosOnly, oneOnly; zerosOnly = oneOnly = 0;

            // loop through row [i][j](looping through the elements of mat[i][j])
            for (int j = 0; j< mat[0].size(); j++){ 
                if (mat[i][j] == 1){
                    one++;
                    colIndx = j;
                }
            }
            if (one == 1){ // this row is special until now, we check the column
                for (int k = 0; k < mat.size(); k++){
                    if (mat[k][colIndx] == 1){
                        oneOnly++;
                    }
                    else zerosOnly++;
                }
                if (oneOnly == 1){
                    ans++;
                }
            }
        }
        return ans;     // return answer
    }
};
