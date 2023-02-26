class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int colOfRow;   //used to store the columne index of minimum element

        int check , k ;
        vector<int>res;   //used to store result
        
        for(int i=0;i<matrix.size();i++)
        {
            int mininrow=INT_MAX;

            for(int j=0;j<matrix[0].size();j++)
            {
                if(mininrow > matrix[i][j])  //find the min element in matrix
                {
                    mininrow = matrix[i][j];   //store the min element
                    colOfRow = j;      //store that index of min element
                }
            }

            check =0;    //used as flag variable

            for(k=0;k<matrix.size();k++)
            {
                if(mininrow < matrix[k][colOfRow])     //iterate that column to find the another max element , if found mark as max elemnent
                {
                    check = 1;
                    break;
                }
            }

            if(check == 0) // if not found that means that element is our lucky no.
            {
                res.push_back(mininrow);    //store in vector
            }
        }       
        
        return res;
    }
};
