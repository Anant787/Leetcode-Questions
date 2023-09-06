class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int cnt = 0;

        for(int i =1;i<nums.size();i++)
        {
            if(cnt == 0 && nums[i] < nums[i-1])
            {
                cnt = -1;   // check decreasing
            }
            else if(cnt == 0 && nums[i] > nums[i-1] )
            {
                cnt = 1;   // check increasing
            }

            else if(cnt == -1 && nums[i] > nums[i-1]) //check the contradict conditions
            {
                return false;
            }
            else if(cnt ==1 && nums[i] < nums[i-1])
            {
                return false;
            }
        }
        return true;
        
    }
};
