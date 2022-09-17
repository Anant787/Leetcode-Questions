class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int>ans(rowIndex+1,1);
        
        
        for(int i=1;i<ans.size()-1;i++)
        {
            for(int j=rowIndex-1;j>=i;j--)
            {
                ans[j]=ans[j+1]+ans[j];
            }
        }
        return ans;
        
    }
};