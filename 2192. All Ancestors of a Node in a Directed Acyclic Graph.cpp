class Solution {
public:

    void bfs(vector<vector<int>> &adj, int src, vector<int> &path)
    {
        int n = adj.size();
        vector<bool> vis(n, false);

        
        queue<int> q;
        q.push(src);
        vis[src] = true;
        
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            if(u != src) path.push_back(u);

            for(auto &v: adj[u])
            {
                if(!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(n, vector<int>());
        for(auto &edge: edges)
        {
            adj[edge[1]].push_back(edge[0]);
        }

        vector<vector<int>> ans;
        for(int node=0 ; node<n ; node++)
        {
            vector<int> path;
            bfs(adj, node, path);
            sort(path.begin(), path.end());
            ans.push_back(path);
        }

        return ans;
    }
};
