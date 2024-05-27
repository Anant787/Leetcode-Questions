// class Solution {
// public:
//  bool fun(int h,vector<int>& nums){
//     int ct=h;
//     for(int i=0;i<nums.size();i++){
//         if(nums[i]>=h)ct--;
//     }
//     return ct==0;
//  }
//     int specialArray(vector<int>& nums) {
//         for(int i=1 ;i<=nums.size();i++){
//             if(fun(i,nums)) return i;
//         }

//         return -1;
//     }
// };
class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0; i<=nums[n-1]; i++){
            int j= lower_bound(nums.begin(),nums.end(),i)-nums.begin();
            cout<<j<<" ";
            if((n-j)==i){
                return i;
            }
        }
        return -1;
    }
};
