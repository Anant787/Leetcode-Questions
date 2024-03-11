class Solution {
public:
    string customSortString(string order, string s) 
    {
        string res = "";
        unordered_map<int, int> mps;   
        for (auto ch : s) mps[ch]++;
        for (auto it : order)
        {
            if (mps.find(it) != mps.end())
            {
                res.append(mps[it], it);
                mps.erase(it);
            }
        }
        for (auto it : mps) res.append(it.second, it.first);
        return res;
    }
};
