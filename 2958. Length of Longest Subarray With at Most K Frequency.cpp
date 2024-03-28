class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
         unordered_map<int, int>mp;
        int ans = 0;
        int r= 0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            while(mp[nums[i]]>k && r<i){
                mp[nums[r]]--;
                r++;
            }
            ans = max(ans, i-r+1);
        }
        return ans;
    }
};
