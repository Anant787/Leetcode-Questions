class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        string ans = "";
        unordered_map<char,int>mp;
        unordered_map<char,int>isTaken;
        
        for(auto i : s)
        {
            mp[i]++;
        }

        for(int i = 0;i<n;i++)
        {
            mp[s[i]]--;

            if(isTaken[s[i]] != 0)
            {
                continue;
            }

            while(!ans.empty() && ans.back() > s[i] && mp[ans.back()] )      //mp[ans.back()] != 0
            {
                isTaken[ans.back()] = 0;
                ans.pop_back();
            }

            ans.push_back(s[i]);
            isTaken[s[i]] = 1;
        }

        return ans;
        
    }
};
