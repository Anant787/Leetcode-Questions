class Solution {
public:
map<int,vector<int>>adj;
map<int,int>IN;
map<int,int>vis;
    vector<int> restoreArray(vector<vector<int>>& adj1) {
        int n=adj1.size();
        for(int i=0;i<n;i++)
        {
            int x=adj1[i][0];
            int y=adj1[i][1];
            adj[x].push_back(y);
            adj[y].push_back(x);
            IN[x]++;
            IN[y]++;
        }
        queue<int>pq;       // using bfs
        for(int i=0;i<n;i++)
        {
            int x=adj1[i][0];
            int y=adj1[i][1];
            if(IN[x]==1)
            {
                pq.push(x);
                break;
            }
            if(IN[y]==1)
            {
                pq.push(y);
                break;
            }
        }
        vector<int>ans;
        while(!pq.empty())
        {
            int p=pq.front();
            pq.pop();
            ans.push_back(p);
            vis[p]=1;
            for(auto it:adj[p])
            {
                if(vis[it]==0)
                {
                    pq.push(it);
                }
            }

        }
        return ans;
    }
};
