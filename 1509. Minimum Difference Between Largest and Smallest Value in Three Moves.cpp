class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n <= 4) return 0;
        vector<int> mini(4), maxi(4), minInd(4), maxInd(4);

        // finding 4 minimum elements of nums
        for(int i=0; i<4; i++)
        {
            minInd[i] = min_element(nums.begin(), nums.end())- nums.begin();
            mini[i] = nums[minInd[i]];
            nums[minInd[i]] = INT_MAX;
        }

        //changing back the values of nums to it's original values
        for(int i=0; i<4; i++)
        {
            nums[minInd[i]] = mini[i];
        }

        // finding 4 maximum elements of nums
        for(int i=0; i<4; i++)
        {
            maxInd[i] = max_element(nums.begin(), nums.end())- nums.begin();
            maxi[i] = nums[maxInd[i]];
            nums[maxInd[i]] = INT_MIN;
        } 
  
        //changing back the values of nums to it's original values
        for(int i=0; i<4; i++)
        {
            nums[maxInd[i]] = maxi[i];
        }

        int ans = INT_MAX;
        for(int i=0; i<4; i++)
        {
            ans = min(ans, maxi[3-i]-mini[i]);
        }
        return ans;
    }
};
