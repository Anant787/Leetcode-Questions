class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int>mp;

        for(int i=0;i<paths.size();i++)
        {
            mp[paths[i][1]]++;         // count the destination 
        }

        for(int i=0;i<paths.size();i++)
        {
            if(mp.count(paths[i][0]))        //if destination is also a starting point 
            {
                mp.erase(paths[i][0]);  // then remove it
            }
        }

        return mp.begin()->first;     // return the ans

        // set<string>s;

        // for(auto row : paths)
        // {
        //     s.insert(row[1]);
        // }

        // for(auto row : paths)
        // {
        //     if(s.count(row[0]) > 0)
        //     {
        //         s.erase(row[0]);
        //     }
        // }

        // for(string ans : s)
        // {
        //     return ans;
        // }

        // return "";

        
    }
};
