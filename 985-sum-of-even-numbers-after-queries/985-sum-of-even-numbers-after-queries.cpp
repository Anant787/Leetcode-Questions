class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        int evensum=0;
        
        for(auto x : nums)
        {
            if(x % 2==0)
            {
                evensum+=x;
            }
        }
        
        vector<int>ans;
        
        for(auto q:queries)
        {
            int val = q[0] , idx = q[1];
            
            if(nums[idx] % 2 == 0)
            {
                evensum-=nums[idx];
            }
            
            nums[idx]+=val;
            
            if(nums[idx] % 2 == 0)
            {
                evensum+=nums[idx];
            }
            
            ans.push_back(evensum);
    }
        return ans;
    }
};