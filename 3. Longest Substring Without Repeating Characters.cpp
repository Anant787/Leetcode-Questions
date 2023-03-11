class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        unordered_map<char,int>mp;
        int ans = INT_MIN;
        
        if(s.size() == 0)      //edge case
        {
            return 0;
        }

        while(j<s.size())
        {
            mp[s[j]]++;
            //for all unique charcter the size of map is equal to window size is must
            if(mp.size() == j-i+1)
            {
                ans = max(ans,j-i+1);
                j++;
            }
            //case of repeating character
            else if(mp.size() < j-i+1)
            {
                while(mp.size() < j-i+1)
                {
                    mp[s[i]]--;

                    if(mp[s[i]] == 0)
                    {
                        mp.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return ans;
        
    }
};
