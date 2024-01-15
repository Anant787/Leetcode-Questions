class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = matches.size();
        map<int,int>mp;           //(KEY,COUNT)  key is for loser and its count in map

        for(int i=0;i<n;i++)
        {
            mp[matches[i][1]]++;
        }

        vector<int>loser;
        vector<int>Winner;

        for(int i=0;i<n;i++)
        {
            if(mp[matches[i][1]]==1)   //Check if its count 1 then push it into loser 
            {
                loser.push_back(matches[i][1]);
            }
            if(mp.find(matches[i][0]) == mp.end() ) //Check the remaining element into the map to end for finding the unknown element as winner element 
            {
                Winner.push_back(matches[i][0]);
                mp[matches[i][0]] = 2; //mark as visited element as flag
            }
        }

        sort(loser.begin(),loser.end());
        sort(Winner.begin(),Winner.end());

        return {Winner,loser};
        
    }
};
