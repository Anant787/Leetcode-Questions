class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1;   //true   : set for first column if it get any zero  
        int row = matrix.size();
        int col = matrix[0].size();

        for(int i=0;i<row;i++)
        {
            if(matrix[i][0] == 0)      
            {
                col0 = 0;       //mark as false,will updated at last for getting the answer
            }
            for(int j=1;j<col;j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = matrix[0][j] = 0;//mark zero in dumby matrix of row and col
                }
            }
        }

        //iterate from the last bcz not to update the dumpy matrix element in ans
        for(int i = row-1;i>=0;i--)
        {
            for(int j = col-1;j>=1;j--)
            {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
            if(col0 == 0)    //if col0 is false mark that element as zero
            {
                matrix[i][0] = 0;
            }
        }
    }
};
