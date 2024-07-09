class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& nums) {
        double wt = 0.0 ,twt = 0.0;

        for(int i=0;i<nums.size();i++)
        {
            if(wt<nums[i][0]){
                wt = nums[i][0]+nums[i][1];
                twt += wt-nums[i][0];
            }
            else {
                wt += nums[i][1];
                twt += wt-nums[i][0];
            }
        }
        
        int n = nums.size();
        double avrg = twt/n;
        return avrg;
    }
};
