class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int>ans; // to store the answer

        int row = matrix.size();   //row
        int col = matrix[0].size();  //column 

        int top = 0 , bottom = row-1;
        int left = 0 , right = col-1;

        while(top <= bottom && left <= right)  //boundary case
        {
            for(int i = left; i <= right ; i++)   //left to right
            {
                ans.push_back(matrix[top][i]);
            }           
            top++;

            for(int i = top; i<= bottom ;i++)   //top to bootom
            {
                ans.push_back(matrix[i][right]);
            }
            right--;

            if(top <= bottom)
            {
                for(int i = right; i >= left ; i--)   //right to left
                {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if(left <= right)
            {
                for(int i = bottom ; i>=top ; i--)  //bottom to top
                { 
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return ans;
        
    }
};
