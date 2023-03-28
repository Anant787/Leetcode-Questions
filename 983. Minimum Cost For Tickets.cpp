class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();

        vector<int>dp(n+31,0);

        for(int i=n-1;i>=0;i--)        //iterate from back side
        {
            int nextday=0;
            //store the lower bound value for day 1 for cost 1
            nextday = lower_bound(days.begin(),days.end(),days[i]+1) - days.begin();
            
            int op1 = costs[0] + dp[nextday];

            nextday = lower_bound(days.begin(),days.end(),days[i]+7) - days.begin();

            int op2 = costs[1] + dp[nextday];

            nextday = lower_bound(days.begin(),days.end(), days[i] + 30) - days.begin();
            int op3 = costs[2] + dp[nextday];

            dp[i] = min(op1 , min(op2,op3));       //minimum of the costs
        }

        return dp[0];
        
    }
};
