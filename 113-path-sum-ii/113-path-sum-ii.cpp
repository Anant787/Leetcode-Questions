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
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int Sum) {
        vector<vector<int>>paths;
        vector<int>path;
        findpaths(root,Sum,path,paths);
        
        return paths;
    }
    
    void findpaths(TreeNode *  node ,int sum,vector<int>&path,vector<vector<int>>&paths)
    {
        if(!node)return ;
        
        path.push_back(node->val);
        
        if(!(node->left)  && !(node->right)  && sum==node->val)
        {
            paths.push_back(path);
        }
        
        findpaths(node->left,sum-node->val,path,paths);
        findpaths(node->right,sum-node->val,path,paths);
        
        path.pop_back();
        
        
    }
};