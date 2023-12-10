class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        // vector<vector<int>> result;
        // int n=matrix.size(),m=matrix[0].size();

        // for(int j=0;j<m;j++)
        // {
        //     vector<int> temp;
        //     for(int i=0;i<n;i++)
        //     {
        //         temp.push_back(matrix[i][j]);
        //     }
        //     result.push_back(temp);
        // }
        // return result;

        vector<vector<int>> ans(matrix[0].size());
        for(int i=0; i<matrix.size(); i++)
        {
          for(int j=0; j<matrix[i].size(); j++)
          {
              ans[j].push_back(matrix[i][j]);
          }
      }  
      return ans;
    }
};
