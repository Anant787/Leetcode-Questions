class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        // Binary Search Approach 
        int i=k,j=k;
        int mn=nums[k];
        int ans=mn;


        while(i>0 or j<nums.size()-1)
        {
            if(i==0 or (j<nums.size()-1 and nums[j+1]>nums[i-1])) 
            {
                j++;
            }
            else
            {
                i--;
            }

            mn=min({mn,nums[i],nums[j]});
            ans=max(ans,mn*(j-i+1));
        }
        return ans;
    }
};
