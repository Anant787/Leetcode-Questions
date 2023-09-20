class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        //Sliding Window Concept
        int totalSum = 0;
        // calculate total sum
        for (int num : nums)
            totalSum += num;
        int maxlen = -1, curSum = 0;
        int l = 0, r = 0, target = totalSum - x;
        //sliding window to find maximum length window,
        //where sum of the window is totalsum - x;
        while(r < nums.size()){
            curSum += nums[r++];
            // resize window if cursum > target
            while(l < r && curSum > target){
                curSum -= nums[l++];
            }
            // update maxlen if cursum == target
            if(curSum == target){
                maxlen = max(maxlen, r - l);
            }
        }
        // maxlen == -1, means window not found that means it not possible
        // other wise return array len - window len
        return maxlen == -1 ? -1 : nums.size() - maxlen;       

    }
};


























// class Solution {
// public:
//     int minOperations(vector<int>& nums, int x) {
        
//         // int count =0 ;
//         // int start = 0;
//         // int end = nums.size()-1;

//         // if(nums[start] > x || nums[end] > x)
//         // {
//         //     return -1;
//         // }


//         // for(int i=0;i<nums.size();i++)
//         // {
//         //     if(nums[start] <= x || nums[end] <= x)
//         //     {
//         //         if(nums[start] <= nums[end])
//         //         {
//         //             x -= nums[end];
//         //             count++;
//         //         }
//         //         else
//         //         {
//         //             x -= nums[start];
//         //             count++;
//         //         }
                
//         //     }
//         //     start++;
//         //         end--;
//         // }
//         // return count;
        
//     }
// };
