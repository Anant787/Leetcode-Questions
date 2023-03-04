class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {

        long res = 0;

        int start = 0,minStart = 0 , maxStart = 0;

        bool minF = false , maxF = false;

        for(int i = 0; i<nums.size();i++)
        {
            int num = nums[i];

            if(num < minK || num > maxK)
            {
                minF = false ;
                maxF = false ; 
                start = i+1;
            }
            if(num == minK)
            {
                minF = true;
                minStart = i;
            }
            if(num == maxK)
            {
                maxF = true;
                maxStart = i;
            }

            //cout<<res<<" ";
            // cout<<maxStart << " "<<endl;
            // cout<<minStart << " ";

            if(minF && maxF)
            {
                res += (min(minStart,maxStart) - start + 1);
            }
        }
        return res;
        
    }
};
