class Solution {
public:
    long long solve(vector<vector<int>>&ques,int n,int ind,vector<long long>&dp){
        if(ind>=n)  //Edge Case
            return 0;

        if(dp[ind]!=-1)
            return dp[ind];

        long long choose=0;
        //Recursive call 
        choose=max(ques[ind][0]+solve(ques,n,ind+ques[ind][1]+1,dp),solve(ques,n,ind+1,dp));
        
        return dp[ind] = choose;  //ans store
    }
    long long mostPoints(vector<vector<int>>& questions) {

        int n = questions.size();
        vector<long long>dp(n,-1);   //DP
        return solve(questions,n,0,dp);

    }
};
