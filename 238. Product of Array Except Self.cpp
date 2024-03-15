class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre , suff;

        pre.push_back(1);
        
        int num = 1, num2 = 1;
        int n = nums.size();
        
        // store previous elements product
        
        for(int i = 1; i < n; i++)
        {
            num *= nums[i - 1];
            pre.push_back(num);
        }
        
        // store next elements product
        
        for(int i = n - 1; i >= 0; i--)
        {
            suff.push_back(num2);
            num2 *= nums[i];
        }
        
        // return the product of pre and suff vectors
        
        for(int i = 0; i < n; i++)
            pre[i] *= suff[n - i - 1];
        return pre;
    }
};
