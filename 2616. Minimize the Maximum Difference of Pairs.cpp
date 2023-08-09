class Solution {
public:
 bool isPossible(int x,vector<int>& nums, int p){
     int pairs =0;

     for(int i=0;i<nums.size()-1;i++){
         if(nums[i+1]-nums[i] <=x){
             pairs++;
             i++;
         }
     }
     return (pairs>=p);
 }

    int minimizeMax(vector<int>& nums, int p) {

        sort(nums.begin(),nums.end());
        int low =0;
        int high= 1e9;

        while(low<high){
            int mid = low +(high-low)/2;

            if(isPossible(mid,nums,p)){
                high =mid;
            }
            else{
                low =mid+1;
            }
            

        }
        return low;

        
    }
};
