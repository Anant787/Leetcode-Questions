class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        int map_s[128] = {};
        int map_t[128] = {};
        
        for(int i=0;i<n;i++)
        {
            if(map_s[s[i]] != map_t[t[i]])      //check the value of element of string s is not equal to the value of element of string t
            {
                return false;
            }
            map_s[s[i]] = i+1;
            map_t[t[i]] = i+1;
        }
        return true;
    }
};
