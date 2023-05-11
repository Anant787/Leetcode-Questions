class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {

        //longest commnon subsequence variation
        //Exact same code

        int m = nums1.size();
        int n = nums2.size();

        int t[m+1][n+1];      //DP 

        for(int i=0;i<m+1;i++)
        {
            for(int j =0;j<n+1;j++)
            {
                if(i==0 || j==0)
                {
                    t[i][j] = 0;
                }
                else if(nums1[i-1] == nums2[j-1])
                {
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else
                {
                    t[i][j] = max(t[i-1][j] , t[i][j-1]);
                }
            }
        }
        return t[m][n];
        
    }
};
