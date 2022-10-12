class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int ans,i;
        
        sort(nums.begin(),nums.end(),greater<int>());
        
        for(i=0;i<nums.size()-2;i++)
        {
            if(nums[i]<nums[i+1] + nums[i+2])
            {
                ans= nums[i]+nums[i+1]+nums[i+2];
                return ans;
            }
        }
        
        return 0;
        
    }
};