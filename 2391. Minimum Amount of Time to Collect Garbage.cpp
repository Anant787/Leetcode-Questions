class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        string st = "MPG";
        int ans = 0;

        for(auto truck: st)
        {
            bool fl = 0;
            for(int i = garbage.size() - 1; i >= 0; i--) 
            {
                for(int j = 0; j < garbage[i].size(); j++) 
                {
                    if(garbage[i][j] == truck) fl  = 1, ans++;
                }
                if(fl && i > 0) 
                {
                    ans += travel[i - 1];
                }    
            }
        }
        return ans;
    }
};
