class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //Easy code
        sort(nums.begin(),nums.end());
        return nums[nums.size()-k];
        
    }
};
