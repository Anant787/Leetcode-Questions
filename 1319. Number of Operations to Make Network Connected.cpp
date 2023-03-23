class Solution {
public:

    //Easy DFS traversal
    void dfs(int i,vector<int>adj[],vector<bool>&vis)
    {
        vis[i] = true;

        for(auto it : adj[i])
        {
            if(vis[it] == false)
            {
                dfs(it,adj,vis);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int edge = connections.size();

        vector<int>adj[n];       //adjcecnt vector
        
        if(edge<n-1)   //edge case
        {
            return -1;
        }

        for(int i=0;i<edge;i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }

        vector<bool>vis(n,false);      //vector to mark visited element
        int ans = 0;          //to store the element

        for(int i=0;i<n;i++)
        {
            if(vis[i] == false)
            {
                dfs(i,adj,vis);
                ans++;
            }
        }

        return ans-1;
    }
};
