class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
    //     map<int,int>mpp;     // map to count the frequency of elememts
    //    // int arr[101]={};
    //     int res=0;
    //     int n=nums.size();
        
    //     for(int i=0;i<n;i++)
    //     {
    //         res+=mpp[nums[i]]++;
    //     }
    //     return res;

        int ans = 0;
        for (int i=0; i<nums.size(); i++) {
            for (int j=i+1; j<nums.size(); j++) {
                if (nums[i] == nums[j]) ans++;
            }
        }
        return ans;

    
        
        
    }
};
