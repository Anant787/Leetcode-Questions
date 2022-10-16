class Solution {
    int t[301][11];
    int solve(vector<int>&jobD,int n,int i,int d)
    {
        if(d==1)
        {
            return *max_element(begin(jobD)+i,end(jobD));
        }
        if(t[i][d] != -1)
        {
            return t[i][d];
        }
        int result = INT_MAX;
        int curr = INT_MIN;
        for(int j=i;j<=n-d;j++)
        {
            curr = max(curr , jobD[j]);
            result = min(result ,curr + solve(jobD,n,j+1,d-1));
        }
        t[i][d] = result;
        return t[i][d];
    }
    
public:
    int minDifficulty(vector<int>& jobD, int d) {
        memset(t,-1,sizeof(t));
        int n = jobD.size();
        if(n<d)
        {
            return -1;
        }
        
        return solve(jobD,n,0,d);
    }
};