class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n =score.size();
        priority_queue<int>maxh;
        vector<int>v;

        vector<string>ans;

        for(int i=0;i<n;i++)
        {
            maxh.push(score[i]);
        }

        unordered_map<int,string>mp;  // map to store the index of elements
        
        int ind = 1;

        while(maxh.size() != 0)
        {
            if(ind == 1)
            {
                mp[maxh.top()] = "Gold Medal";
                maxh.pop();
                ind++;
            }
            else if(ind == 2)
            {
                mp[maxh.top()] = "Silver Medal";
                maxh.pop();
                ind++;
            }
            else if(ind == 3)
            {
                mp[maxh.top()] = "Bronze Medal";
                maxh.pop();
                ind++;
            }
            else 
            {
                mp[maxh.top()] = to_string(ind);
                maxh.pop();
                ind++;
            }
        }

        for(int i=0;i<n;i++)
        {
            ans.push_back(mp[score[i]]);
        }

        return ans;
    }
};
