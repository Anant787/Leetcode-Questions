class Solution {
public:
    int minPatches(vector<int>& nums, int n) {

        int patch=0;
        long max=0;
        int i=0;
        while(max<n){
            if(i<nums.size() && nums[i]<= max+1){
                max += nums[i];
                i++;
            }else{
                max += max+1;
                patch +=1 ;
            }
            
        }
        return patch;
        
    }
};
