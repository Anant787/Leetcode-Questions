class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>map;
        for(int i=0;i<s.length();i++)
        {
            map[s[i]]++;
        }
        
        int count=0;
        for(auto i : map)
        {
            if(i.second % 2 != 0)
            {
                count++;
            }
        }
        
        if(count>1)
        {
            return s.length() - count+1;
        }
        
        return s.length();
        
        
    }
};