class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v(numRows);   //create vector of vector of size numsRow

        for(int i=0;i<numRows;i++)  
        {
            v[i].resize(i+1);  //resize the vector as increasing equal no. of row and column

            v[i][0] = v[i][i] = 1;  //boundary of pascal triangle is always 1 

            for(int j=1;j<i;j++)
            {
                v[i][j] = v[i-1][j-1] + v[i-1][j]; //add the previous element to next element
            } 
        }
        return v;          //return the vector
    }
};
