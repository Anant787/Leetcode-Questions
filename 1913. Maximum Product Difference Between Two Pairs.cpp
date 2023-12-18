class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());     // sort the array

        int ans=0;
        
        int n = nums.size();
        
        ans = (nums[n-2]*nums[n-1]) - (nums[0]*nums[1]);     // store the answer
        
        return ans;
    }
};
