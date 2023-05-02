class Solution {
public:
    int signFunc(int k)
    {
        if(k>0)
        {
            return 1;
        }
        else if(k<0)
        {
            return -1;
        }
        else{
            return 0;
        }
        
    }
    
    int arraySign(vector<int>& nums) {
        int product=1;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
        
            if(nums[i]<0)
            {
                product*=-1;
            }
            if(nums[i]==0)
            {
                product*=0;
            }
        
        }
        return signFunc(product);
    }
};
