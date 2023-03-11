class Solution {
public:
    string replaceDigits(string s) {
        int n = s.size();

        for(int i=0;i<n;i++)
        {
            if(s[i] >= 48 && s[i] <= 57)
            {
                s[i] = s[i-1]+(s[i]-'0');
            }
        }
        return s;
    }
};
