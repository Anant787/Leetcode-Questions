class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // int n = nums.size();
        // int before = 0;
        // int after = 0;
        // int maxi = 0;
        // bool flag = false;
        // for(int i = 0; i < n; ++i){
        //     if(nums[i] == 1) flag?after++:before++;
        //     if(i > 0 && i < n && nums[i] == 0 && nums[i-1] == 1 && nums[i+1] == 1){
        //         if(flag){
        //             before = after;
        //             after = 0;
        //         }else{
        //             flag = true;
        //         }
        //     }
        //     if(i > 0 && nums[i] == 0 && nums[i-1] == 0){
        //         flag = false;
        //         after = 0;
        //         before = 0;
        //     }
        //     maxi = max(maxi,before+after);
        // }
        // return maxi==n?--maxi:maxi;

         vector<int>zero;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zero.push_back(i);
            }
        }
        if(zero.size()==0) return nums.size()-1;
        if(zero.size()==nums.size()) return 0;

        long long int ans=0;
        int i=0;
        while(i<zero.size()){
            int j=zero[i]-1;
            int left=0,right=0;
            while(j>=0 && nums[j]==1){
                j--;
                left++;
            }
            j=zero[i]+1;
            while(j<nums.size() && nums[j]==1){
                j++;
                right++;
            }
            if(ans<=(left+right)) ans=left+right;
            i++;
        }
        return ans;
    }
};
