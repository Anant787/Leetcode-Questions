// class Solution {
// public:
//   vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
//     if (n <= 1) {
//       return vector<int>(n); // All nodes are MHTs for n <= 1
//     }
    
//     // Build adjacency list
//     vector<vector<int>> graph(n);
//     for (const vector<int>& edge : edges) {
//       graph[edge[0]].push_back(edge[1]);
//       graph[edge[1]].push_back(edge[0]);
//     }
    
//     // Find leaf nodes
//     vector<int> leaves;
//     for (int i = 0; i < n; ++i) {
//       if (graph[i].size() == 1) {
//         leaves.push_back(i);
//       }
//     }
    
//     // Iterative removal
//     while (n > 2) {
//       n -= leaves.size();
//       vector<int> newLeaves;
//       for (int leaf : leaves) {
//         int neighbor = graph[leaf][0];
//         graph[neighbor].erase(remove(graph[neighbor].begin(), graph[neighbor].end(), leaf), graph[neighbor].end());
//         if (graph[neighbor].size() == 1) {
//           newLeaves.push_back(neighbor);
//         }
//       }
//       leaves = newLeaves;
//     }
    
//     return leaves;
//   }
// };
class Solution {
public:
   
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 2)return {0,1};
        if(n == 1)return {0};
        vector<vector<int>> adj(n);
        vector<int> degree(n,0);
        for(auto& i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            degree[i[0]]++;
            degree[i[1]]++;
        }   
        queue<int> q;
        for(int i = 0;i < n ;i++){
            if(degree[i] == 1){
                q.push(i);
                degree[i]--;
            }
        }
        int nodes = n;
        while(!q.empty()){
            int n = q.size();
            nodes -= n;
            while(n--){
                int x = q.front();
                q.pop();
                for(int& i : adj[x])if(--degree[i] == 1)q.push(i);
            }
            if( nodes <= 2)break;
        }
        vector<int> ans;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            ans.push_back(x);
        }
        return ans;
    }
};
