class Solution {
public:
    int dp[1001][1001];  // global declare
    bool isPalindromicIterative(string & s,int st,int e)    // check for palindrome iterative
    {
        while(st<e)
            if(s[st++] != s[e--])
                return false;

        return true;
    } 
    bool isPalindromicRecursive(string & s,int st,int e) //palindrome recursive
    {
            if(st>=e)return true;
            //MEMORIZATION
            if(dp[st][e]!= -1)return dp[st][e];
            //RECURISON
            if(s[st]== s[e])
                return isPalindromicRecursive(s,st+1,e-1);
            return false;
    }
    string longestPalindrome(string s) {
        // APPROACH -1 (ITERATIVE)
        // string ans= "";
        // int n = s.size();
        // for(int i=0;i<n;i++)
        //     for(int j=i;j< n;j++)
        //         if(isPalindromicIterative(s,i,j))
        //         {
        //             string t = s.substr(i,j-i+1);
        //             ans = t.size()>ans.size()?t:ans;
        //         }
        // return ans;

        // APPROACH -2 (RECURSIVE  + DP)
        memset(dp,-1,sizeof(dp));
        int n = s.size();
        int maxlen = INT_MIN;
        int st = 0;

        for(int i=0;i<n;i++)
            for(int j=i;j<n;j++)
                if(isPalindromicRecursive(s,i,j))
                {
                    if(j-i+1 > maxlen)
                    {
                        maxlen = j-i+1;
                        st=i;
                    }
                }
        
        return s.substr(st,maxlen);
    }
};
