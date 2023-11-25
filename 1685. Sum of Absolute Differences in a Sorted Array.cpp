class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans,prefix(n,0);
        
        prefix[0] = nums[0];
        //calculate prefix sum
        
        for(int i=1; i<nums.size(); i++)
        {
            prefix[i] = prefix[i-1] + nums[i];
        }

        //for elements in the left of nums[i] -> left sum = (i+1)*nums[i] - prefix[i]
        
        //for elements in the right of nums[i] -> riight sum = (prefix[n-1] - prefix[i]) - (n-i-1)*nums[i]
        
        //answer for nums[i] is - the sum of above left sum and right sum
        
        for(int i=0; i<nums.size(); i++)
        {
            ans.push_back((i+1)*nums[i] - prefix[i] + (prefix[n-1] - prefix[i]) - (n-i-1)*nums[i]);
        }
     return ans;
    }
};
