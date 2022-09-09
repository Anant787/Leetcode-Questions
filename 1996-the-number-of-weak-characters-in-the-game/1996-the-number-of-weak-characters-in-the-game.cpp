class Solution {
    static bool comp(vector<int>&a,vector<int>&b)
    {
        if(a[0]==b[0])
        {
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
public:
    int numberOfWeakCharacters(vector<vector<int>>& P) {
        
        sort(P.begin(),P.end(),comp);
        int n=P.size();
        int ans=0;
        
        int game=INT_MIN;
        
        for(int i=n-1;i>=0;i--)
        {
            if(P[i][1]<game)
            {
                ans++;
            }
            game=max(game,P[i][1]);
        }
        return ans;
    }
};