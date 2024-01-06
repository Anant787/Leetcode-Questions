class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({endTime[i],startTime[i],profit[i]});
        }
        sort(v.begin(),v.end());
        vector<int>dp(n,0);
        dp[0] = v[0][2];           //end and profit
        int ans = dp[0];

        for(int i=1;i<n;i++)
        {
            int incl = v[i][2];     //for job scheduling
            dp[i] = incl;
            int curr = i;
            int l = Search(v,curr);
            if(l!=-1)
            {
                dp[i] +=dp[l];
            }
            dp[i] = max(dp[i],dp[i-1]);
            ans = max(ans,dp[i]);
        }       
        return ans;
    }
    int Search(vector<vector<int>>&v,int curr)
    {
        int l =0;
        int r = curr-1;
        int ans=-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(v[mid][0]<=v[curr][1])
            {
                ans=mid;
                l = mid+1;
            }
            else
            {
                r = mid-1;
            }
        }
        return ans;
    }
};
