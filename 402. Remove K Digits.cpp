class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        for (int i = 0; i < num.length(); i++) 
        {
            while (!ans.empty()) 
            {
                if (k <= 0) break;
                if (ans.back() > num[i])
                {
                    ans.pop_back();
                    k--;
                }
                else break;
            }
            if (!ans.empty() || num[i] != '0') ans.push_back(num[i]);
        }
        while (!ans.empty()) 
        { 
            if (k <= 0) break;
            ans.pop_back();
            k--;
        }
        if (ans == "") return "0";
        return ans;
    }
};
