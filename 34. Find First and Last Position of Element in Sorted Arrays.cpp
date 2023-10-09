class Solution {
public:
    int FirstElement(vector<int>&nums,int target)   // to find the first occurence of the target element
    {
        int start = 0;
        int end = nums.size()-1;
        int res = -1;

        while(start <= end)
        {
            int mid = start + (end - start)/2;

            if(target == nums[mid])
            {
                res = mid;
                end = mid-1;             //must condition for first occurence
            }
            else if(target < nums[mid])
            {
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
        return res;
    }

    int LastElement(vector<int>&nums,int target)   //to find the last occurence of target elements
    {
        int start = 0;
        int end = nums.size()-1;
        int res = -1;

        while(start <= end)
        {
            int mid = start + (end - start)/2;

            if(target == nums[mid])
            {
                res = mid;
                start = mid+1;          //must condition for last occurence of target element
            }
            else if(target < nums[mid])
            {
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
        return res;
    }

    vector<int> searchRange(vector<int>& nums, int target) {

        // binary Search Approach 
        int n = nums.size();

        if(n == 0)          //edge case
        {
            return {-1,-1};
        }

        vector<int>ans;
        int first = FirstElement(nums,target);
        int last = LastElement(nums,target);

        ans.push_back(first);
        ans.push_back(last);

        return ans;
        
    }
};
