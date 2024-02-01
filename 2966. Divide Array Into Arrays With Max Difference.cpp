class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>>ans;

        sort(nums.begin(),nums.end());
        
        if(n%3!=0){
            return {};
        }
        
        for(int i=0;i<n;i+=3)
        {
            if(abs(nums[i+2]-nums[i])<=k){
                ans.push_back({nums[i],nums[i+1],nums[i+2]});
            }
            else{
                return {}; 
            }
            
        }
        return ans;
    }
};
