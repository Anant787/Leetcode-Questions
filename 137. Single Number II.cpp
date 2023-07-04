class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int , int> count ;
        int ans;
        for(int i=0 ;i<nums.size() ;i++){
            count[nums[i]]++ ;
        }
        for(int i=0 ;i<nums.size();i++){
            if(count[nums[i]]==1){
                ans = nums[i] ;
                break ;
            }
        }
        return ans ;

        // int n = nums.size();
        // if (n<3) return nums[0];
        // if (n==3)
        // {
        //     if (nums[0]==nums[1] && nums[1]==nums[2]) return 0;
        //     else return nums[0];
        // }
        // sort(nums.begin(), nums.end());
        // for (int i=0; i<n-2; i++)
        // {
        //     if (nums[i]!=nums[i+1] && nums[i+1]!=nums[i+2]) return nums[i+1];
        // }
        // if (nums[n-2]==nums[n-3] && nums[n-2]!=nums[n-1]) return nums[n-1];
        // if (nums[n-2]!=nums[n-3] && nums[n-2]!=nums[n-1]) return nums[n-2];
        // return nums[0];

}
};
