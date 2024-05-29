class Solution {
public:
    int numSteps(string s) {
        int ans=0;
        while(s.size()>1)
        {
            ans++;
            if(s.back()=='0')
            s.pop_back();
            else
            {
                int i=s.length()-1;
                while(i>=0 && s[i]!='0')
                {
                    s[i]='0';
                    i--;
                }
                if(i>=0)
                {
                    s[i]='1';
                }
                else
                {
                    s='1'+s;
                }
            }
        }
        return ans;
    }
};
