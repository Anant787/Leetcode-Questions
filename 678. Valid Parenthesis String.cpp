class Solution {
public:
    bool checkValidString(string s) {
        int mn = 0, mx = 0;

        for(char c : s)
        {
            mn += (c == '(') ? 1 : -1;
            mx += (c != ')') ? 1 : -1;
           
            if(mx < 0)
                return false;
            mn = max(mn, 0);
        }
        return mn == 0;
    }
};
