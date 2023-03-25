class Solution {
public:
    vector<int> vis;         //globally define vis vector

    //dfs to count the cluster or disjoint graph
    int dfs(vector<vector<int>> &adj,int i){

        vis[i]=1;

        int ans=1;
        for(auto &j:adj[i]){
            if(!vis[j]){
                ans+=dfs(adj,j);      //iterate over that node
            }
        }
        return ans;
    }

    long long countPairs(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);  //adjacency list
        vis=vector<int>(n,0);

        for(auto &i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        vector<int> cluster;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                int x=dfs(adj,i);
                cluster.push_back(x);
            }
        }

        long long ans=0;
        long long t=0;

        //cluster size => 4 2 1 : 4*3=12, 2*1=2 ====> 12+2 = 14 total
        for(int i=0;i<cluster.size();i++){
            t += cluster[i];
            ans += (n-t) * cluster[i];
        }
        return ans;
    }
};
