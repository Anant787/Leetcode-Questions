class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int start=0,end=0,n=nums.size(),freq=0;
        long long ans=0;
        int el=*max_element(nums.begin(),nums.end());
        while(end<n){
            if(nums[end]==el){ freq++ ;}
            while(start<n && freq>=k){
                if(nums[start]==el){ freq--; }
                start++;
                ans+=n-end;
            }
            end++;
        }
        return ans;
    }
};
