/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
 
map<int,int>m;
class Solution {
public:
    TreeNode* help(int node,vector<pair<int,int>> adj[]){
        TreeNode* root=new TreeNode(node);
        cout<<node<<endl;
        for(auto x:adj[node]){
            if(x.second==1){
                root->left=help(x.first,adj);
            }
            if(x.second==0){
                root->right=help(x.first,adj);
            }
        }
        return root;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        TreeNode* root = NULL;
        int n = -1;
        m.clear();
        for(auto x:descriptions){
            m[x[1]]++;
        }
        queue<int>q;
        vector<pair<int,int>>adj[100001];
        for(auto x:descriptions){
            adj[x[0]].push_back({x[1],x[2]});
        }
        int node=-1;
        for(auto x:descriptions){
            if(m[x[0]]==0){
                node=x[0];
            }
        }
        return help(node,adj);
    }
};
