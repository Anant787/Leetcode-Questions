class Solution {
public:
    static bool comp(pair<int,char>&p1,pair<int ,char>&p2)
    {
        return p1.first>p2.first;
    }

    string frequencySort(string s) {
        int n =s.size();
        unordered_map<char,int>mp;
        
        string res;

        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }
        vector<pair<int,char>>v;
        for(auto x:mp)
        {
            v.push_back({x.second,x.first});
        }
        sort(v.begin(),v.end(),comp);

        for(auto it : v)
        {
            int count= it.first;
            cout<<count<<" ";
            int j=0;
            while(j<count)
            {
                res.push_back(it.second);
                j++;
            }
        }

        return res;
    }
};
