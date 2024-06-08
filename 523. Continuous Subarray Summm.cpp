class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>prefixMod(n+1,0);
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            prefixMod[i+1] = sum % k;
        }
        unordered_map<int,int>mp;
        for(int i = 0; i < n+1; i++){
            auto it = mp.find(prefixMod[i]);
            if(it != mp.end()){
                if(i - it->second >= 2) return true;
            }else{
                mp[prefixMod[i]] = i;
            }
        }
        return false;
    }
};
