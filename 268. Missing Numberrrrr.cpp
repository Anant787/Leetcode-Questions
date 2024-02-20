# Code
```
class Solution {
public:
    int missingNumber(vector<int>& nums) {

       int n= nums.size();
       int sum =0;
       for(int i=0;i<n;i++)
       {
           sum +=nums[i];
       }

       return (n*(n+1)/2)-sum;
        
        // int ans=0,i=0;
        // for(;i<n;i++)
        // {
        //     ans += (i-nums[i]);
        // }
        // return ans+i;

    }
};
```
