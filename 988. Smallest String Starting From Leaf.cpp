/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//using DFS
 class Solution {
 public:
     string result = "";
     void dfs(TreeNode* root, string curr) {
         if(root == NULL)
            return;

        curr = char(root->val + 'a') + curr;

        if(!root->left && !root->right) {
            if(result == "" || result > curr) {
                result = curr;
            }
        }
        dfs(root->left, curr);
        dfs(root->right, curr);
    }
    string smallestFromLeaf(TreeNode* root) {
        //using DFS
        dfs(root, "");

        return result;
    }
};

//using BFS

// class Solution {
// public:
//     string smallestFromLeaf(TreeNode* root) {
//         ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//         string result = "";
//         queue<pair<TreeNode*, string>> q;
//         q.push({root, string(1, char(root->val + 'a'))});

//         while(!q.empty()) {
//             auto[node, curr] = q.front();
//             q.pop();

//             if(!node->left && !node->right) {
//                 if(result == "" || result > curr) {
//                     result = curr;
//                 }
//             }

//             if(node->left) {
//                 q.push({node->left, char(node->left->val + 'a') + curr});
//             }

//             if(node->right) {
//                 q.push({node->right, char(node->right->val + 'a') + curr});
//             }
//         }

//         return result;
//     }
// };
