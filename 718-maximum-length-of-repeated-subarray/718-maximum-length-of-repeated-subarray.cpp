class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (nums1[i-1] == nums2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = 0;
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
        
//         int m=nums1.size();
//         int n=nums2.size();
//         int ans=0;
        
//         vector<vector<int>>t(m+1,vector<int>(n+1));
        
//        // int t[m+1][n+1];
        
//         for(int i=1;i<=m;i++)
//         {
//             for(int j=1;i<=n;j++)
//             {
//                     if(nums1[i-1] == nums2[j-1])
//                     {
//                         t[i][j] = 1 + t[i-1][j-1];
//                     }
//                     else
//                     {
//                         t[i][j]=0;
//                     }
//                     ans = max(ans,t[i][j]);
//             }
            
//         }
        
//         return ans;
    }
};