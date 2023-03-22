class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {

        //BFS traversal

        vector<vector<pair<int,int>>>adj(n+1);  //adjacency matrix
        vector<bool>vis(n+1,false);            //vector to mark the visited node
        queue<int>q; 
        int ans = INT_MAX;            //for returing the ans

        for(auto &r : roads)
        {
            int a = r[0];       //first city
            int b = r[1];       //second city
            int d = r[2];       //distance

            adj[a].push_back({b,d});
            adj[b].push_back({a,d});
        }

        q.push(1);      //push the first city and marks as visited
        vis[1] = true;

        while(!q.empty())      //iterate over the all the element
        {
            int node = q.front();
            q.pop();

            for(auto &r: adj[node])
            {
                ans = min(ans,r.second);  //find minimum distance
                if(!vis[r.first])          //check for the visit
                {
                    q.push(r.first);
                    vis[r.first]= true;
                }
            }
        }

        return ans;
        
    }
};
