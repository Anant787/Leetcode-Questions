class Solution {
public:
    int dpfun(int curr, int lastChar, vector<vector<int>> &dp, string &s, int &k){
        if(curr == s.length()){
            return 0;
        }
        else if(dp[curr][lastChar + 1]!=-1){
            return dp[curr][lastChar + 1];
        }
        else{
            //cout<<curr<<" "<<lastChar<<" "<<abs(lastChar - s[curr]-'a')<<"\n";
            
            if(lastChar == -1 or abs(lastChar - (s[curr]-'a'))<=k){
                //cout<<"first"<<" ";
                return dp[curr][lastChar+1] = max(1 + dpfun(curr+1,s[curr]-'a',dp,s,k), dpfun(curr+1,lastChar,dp,s,k));
            }
            else{
                return dp[curr][lastChar + 1] = dpfun(curr+1,lastChar,dp,s,k);
            }
        }
    }
    int longestIdealString(string s, int k) {
        vector<vector<int>> dp(s.length()+10, vector<int>(28,-1));
        return dpfun(0, -1 , dp, s, k);
    }
};
