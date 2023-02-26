class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>s;
        vector<int>v(nums.size() ,-1);
        //unordered_map<int,int>mp;

        for(int i =nums.size()-1;i>=0;i--)
        {
            s.push(nums[i]);
        }

        for(int i=nums.size()-1;i>=0;i--)
        {
            while(s.size() > 0 && s.top() <= nums[i])
            {
                s.pop();
            }
            if(s.size() != 0)
            {
                v[i] = s.top();
            }
            s.push(nums[i]);
        }

        return v;
    }
};
