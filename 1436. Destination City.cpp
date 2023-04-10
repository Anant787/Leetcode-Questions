class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        //Map approach
        unordered_map<string,int>mp;

        for(int i=0;i<paths.size();i++)
        {
            mp[paths[i][1]]++;  //put the destination value into map
        }

        for(int i=0;i<paths.size();i++) //check for the source value
        {
            if(mp.count(paths[i][0]))
            {
                mp.erase(paths[i][0]);
            }
        }

        return mp.begin()->first;  //return remaining element


        //set Approach
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
