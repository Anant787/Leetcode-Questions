class Solution {
public:
    // DFS approach 
    bool dfs(int node, vector<int> adj[], vector<int>& vis){
        if(vis[node]) return false;
        bool ans = true;
        vis[node] = 1;
        for(auto&i:adj[node]){
            ans = ans and dfs(i, adj, vis);
        }
        return ans;
    }

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> adj[n], vis(n), in(n), out(n);
        // calculate the indegrees of the node.
        for(int i = 0; i < n; i++){
            if(leftChild[i] != -1){
                adj[i].push_back(leftChild[i]);
                in[leftChild[i]]++;
            }
            if(rightChild[i] != -1){
                adj[i].push_back(rightChild[i]);
                in[rightChild[i]]++;
            }
        }
        // count the number of roots i.e. nodes with indegrees zero
        int root = -1;
        for(int i = 0; i < n; i++){
            if(!in[i]){
                // if more than 1 root, return false
                if(root != -1) return false;
                else root = i;
            }
        }
        // if no root or cycle return false
        if(root == -1 or !dfs(root, adj, vis)) return false;
        // if forest, return false
        for(auto&i:vis) if(!i) return false;
        return true;
    }
};
