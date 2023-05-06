class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {

        sort(nums.begin(),nums.end()); //sort the array
        
        int ans=0;  // for storing the answer
        int mod=1e9+7;
        
        vector<int>pow(nums.size(),1);  //vector
        
        int l=0,r=nums.size()-1;
        
        for(int i=1;i<nums.size();i++)
        {
            pow[i]=(pow[i-1]*2)%mod;
        }
        
        //Binary Search
        while(l<=r)
        {
            if(nums[l]+nums[r]>target)
                r--;
            else
            {
                ans=(ans+pow[r-l])%mod;
                l++;

            }
        }
        return ans;
        
    }
};
