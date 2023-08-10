class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // at first look it is prolly a BS problem
        int low = 0, high = nums.size() - 1;
        while(low <= high){
            int mid = (low + high) >> 1;

            // base case
            if(nums[mid] == target) return true;

            // if we encounter duplicate decrease the searching length
            if(nums[mid] == nums[low] and nums[high] == nums[mid]){
                low++;
                high--;
            }

            // If the left half is sorted.
            else if(nums[low] <= nums[mid]){
                // If the target is within the range of the sorted left half.
                if(nums[low] <= target and nums[mid] > target)
                    high = mid - 1;
                else
                    low = mid + 1;
            }

            // if the right half is sorted
            else{
                // If the target is within the range of the sorted right half.
                if(nums[mid] < target and nums[high] >= target)
                    low = mid + 1;
                else
                    high = mid - 1; 
                
            }
        }
// if our Target element is not found
        return false;
    }
};
