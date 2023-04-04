class Solution {
public:
    int partitionString(string s) {

        //using sliding window

        int count=0;
        int n=s.size();
        int i=0,j=0;

        map<char,int>mp;
        while(j<n)
        {
            mp[s[j]]++;

            if(mp.size() < j-i+1)
            {
                mp.clear();
                mp[s[j]]++;
                i=j;
                count++;
                j++;
            }
            else if(mp.size() == j-i+1)
            {
                j++;
            }
        }

        return count+1;
        

        // Using set
        // unordered_set<char>str;
        // int count=1;

        // for(int i=0;i<s.size();i++)
        // {
        //     if(str.find(s[i]) != str.end())
        //     {
        //         count++;
        //         str.clear();
        //     }
        //     str.insert(s[i]);
        // }

        // return count;
    }
};
