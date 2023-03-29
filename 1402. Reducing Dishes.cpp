class Solution {
public:
    int helper(vector<int>&nums,int i,int j,vector<vector<int>>&dp)
    {
        if(i == nums.size())  //edge case
        {
            return 0;
        }

        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }

        //choose the dish and multiplied by time(j) coeficient and call for next element
        int pick = j * nums[i] + helper(nums,i+1,j+1,dp);

        //not include the element
        int not_pick = helper(nums,i+1,j,dp);

        return dp[i][j] = max(pick,not_pick); //return the maximum element
    }

    int maxSatisfaction(vector<int>& sat) {
        int n = sat.size();

        sort(sat.begin(),sat.end()); //sort the array

        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));  //2D  matrix

        return helper(sat,0,1,dp);  //calling helper funtion
    }
};
