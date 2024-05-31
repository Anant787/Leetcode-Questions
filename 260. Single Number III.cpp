class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        for(auto i: nums) x ^= i;
        int n = nums.size();
        int ind = 0;
        while(x){
            if(x & 1) break;
            ind++;
            x = x>>1;
        }

        int xor1 = 0, xor2 = 0;

        for(int i = 0 ; i < n ; i++){
            if(nums[i] & (1 << ind)) xor1 ^= nums[i];
            else xor2 ^= nums[i];
        }

        return {xor1,xor2};
    }
};
