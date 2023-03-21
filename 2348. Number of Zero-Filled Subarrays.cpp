class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long int ans = 0 ,count=0;

        for(auto x : nums)
        {
            if(x)         //condition true for element other than 0
            {
                count=0;
            }
            else          //true for 0
            {
                count++;
            }

            ans+=count;    //add the count of zero which is continues
        }

        return ans;
    }
};
