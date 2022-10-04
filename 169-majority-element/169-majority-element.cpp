class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
       // sort(nums.begin(),nums.end());
        
        int count=0;
        int temp;
        
        for(int i = 0;i<nums.size();i++)
        {
            if(count)
            {
                count+=(nums[i]==temp?1:-1);
            }
            else
            {
                temp = nums[i];
                count = 1 ;
            }
        }
        return temp;
    }
};