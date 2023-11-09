class Solution {
 private: int mod = 1e9+7;
public:
    int countHomogenous(string s) {
        long long ans=0;

        for(int start = 0,end = 0; end<s.size(); end++)
        {
            if(s[start]==s[end])
            {
                long long appear = end-start+1;
                ans = ans + appear;
            }
            else
            {
                start = end;
                ans++;
            }
        }
        return static_cast<int>(ans%mod);
    }
};
