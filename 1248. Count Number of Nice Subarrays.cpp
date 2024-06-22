class Solution {
public:
    int numberOfSubarrays(std::vector<int>& nums, int k) {
        int ans=0,cnt=0,i=0,j=0;

        for(auto num:nums){
            if(num%2!=0){
                k--;
                cnt=0;
            }

            while(k==0){
                if(nums[i]%2!=0) k++;
                cnt++;
                i++;
            }
            ans+=cnt;
        }

        return ans;
    }
};
