class Solution {
public:
    const int mod=1e9+7; // global declare
    int dfs(int src,int n,vector<vector<int>>& adj,vector<vector<int>>& dp)
    {
        if(n==0)return 1;//desired length is obtained 
        
        if(dp[src][n]!=-1)return dp[src][n];

        int ans=0;
        
        for(auto node:adj[src]){
            ans=(ans+dfs(node,n-1,adj,dp))%mod;
        }
        
        return dp[src][n]=ans;
    }
    int countVowelPermutation(int n) {
       vector<vector<int>>adj(5);
        //dp table to hold values of calculation

       vector<vector<int>>dp(5,vector<int>(n+1,-1));
    // formation of graph

        // Cases
       adj[0]={1};
       adj[1]={0,2};
       adj[2]={0,1,3,4};
       adj[3]={2,4};
       adj[4]={0};

       int ans=0;
       
       for(int i=0;i<5;i++)
            ans=(ans+dfs(i,n-1,adj,dp))%mod;//call dfs from every node
       
       return ans;
    }
};
