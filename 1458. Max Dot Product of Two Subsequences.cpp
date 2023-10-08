class Solution {
public:
    // int dp[501][501][2]; // not working properly.
    // int help(int i , int  j, vector<int>&nums1 , vector<int>&nums2,int l)
    // {   
    //     if(i == nums1.size() || j == nums2.size())
    //     {
    //         if(l == 1)
    //         {
    //             return 0;
    //         }
    //         else
    //             return -1;
    //     }

    //     if(dp[i][j][l] != INT_MIN)
    //     {
    //         return dp[i][j][l];
    //     }
    //     else
    //     {
    //         int op1 = nums1[i] * nums2[j] + help(i+1,j+1,nums1,nums2,l);
    //         int op2 = help(i+1,j,nums1,nums2,l);
    //         int op3 = help(i,j+1,nums1,nums2,l);

    //         return dp[i][j][l] = max(op1,max(op2,op3)); 
    //     }
    // }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {

        // from line 31 to 51 only

        int m = nums1.size();
        int n = nums2.size();

        if (m < n) {
            return maxDotProduct(nums2, nums1);
        }

        vector<long> dp(n + 1, INT_MIN);

        for (int i = 0; i < m; i++) {
            long prev = 0;
            for (int j = 0; j < n; j++) {
                long tmp = dp[j + 1];
                dp[j + 1] = max(prev + (long)nums1[i] * nums2[j], max((long)nums1[i] * nums2[j], max(dp[j], dp[j + 1])));
                prev = tmp;
            }
        }

        return (int)dp[n];     

        // for(int i = 0 ;i < nums1.size() ; i++)
        // {
        //     for(int j = 0; j <nums2.size();j++)
        //     {
        //         dp[i][j][0] = INT_MIN;
        //         dp[i][j][1] = INT_MIN;
        //     }
        // }

        // int ans = help(0,0,nums1,nums2,0);

        // if(ans == -1)
        // {
        //     sort(nums1.begin(),nums1.end());
        //     sort(nums2.begin(),nums2.end());

        //     return max(nums1.front() * nums2.back() , nums2.front() * nums1.back());
        // }
        // else return ans;
        
    }
};
