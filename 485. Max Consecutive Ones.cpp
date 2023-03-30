class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0; //store the count
        int mx=0;     // store the maximum count
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == 1)
            {    
                count++;
                mx = max(mx,count);    //count the max 1
            }
            else
            {
                count = 0 ;
            }
        }
        return mx;  //return maximum 1
        
    }
};
