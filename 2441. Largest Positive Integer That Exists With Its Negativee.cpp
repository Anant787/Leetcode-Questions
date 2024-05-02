class Solution {
public:
    int findMaxK(vector<int>& nums) {

        int n = nums.size();
        unordered_map<int,bool>mp;
        int ans = -1;
        for(int i = 0;i<n;i++)
        {
            if(nums[i] < 0)
            {
                mp[nums[i]] = true;
            }
        }

        for(int i = 0 ;i<n;i++)
        {
            if(nums[i] > ans)
            {
                int temp = nums[i] * (-1);
                
                if(mp.find(temp) != mp.end())
                {
                    ans = nums[i];
                }
            }
        }
        return ans;

    }
};
