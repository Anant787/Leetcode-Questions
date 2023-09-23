class Solution {
public:
    
    int find(string &s, string &t){
         int n=s.length();
         int m=t.length();

         if((n+1)!=m) return false;

         int i=0;
         int j=0;

         while(i<n && j<m){
             if(s[i]==t[j]) i++;
             j++;
         }

         return i==n;
    }
    
    bool static comp(string &s1, string &s2){
        return s1.length()<s2.length();
    }

    int solve(vector<string>& words, int prev, int curr, vector<vector<int>> &dp){
        if(curr==words.size()) return 0;

        if(dp[curr][prev+1]!=-1) return dp[curr][prev+1];

        if(prev==-1 || (find(words[prev],words[curr])==true)){
            return dp[curr][prev+1]=max(solve(words,prev,curr+1,dp),1+solve(words,curr,curr+1,dp));
        }
        else {
            return dp[curr][prev+1]=solve(words,prev,curr+1,dp);
        }

        return -1;
    }

    int longestStrChain(vector<string>& words) {
        //LIS sub problem
        
        sort(words.begin(),words.end(),comp);
        
        int n=words.size();
        vector<vector<int>> dp(n+1,vector<int>(n+2,-1));
        
        return solve(words,-1,0,dp);
    }
};
