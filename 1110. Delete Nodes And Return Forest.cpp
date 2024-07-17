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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        recur(root,true,res,to_delete);
        return res;
    }

private:
    void recur(TreeNode*& node, bool isRoot, vector<TreeNode*>& res, vector<int>& to_delete) {
        if (node==nullptr) return;
        if (find(to_delete.begin(),to_delete.end(),node->val)!=to_delete.end()) {
            recur(node->left,true,res,to_delete);
            recur(node->right,true,res,to_delete);
            node = nullptr;
            return;
        }
        recur(node->left,false,res,to_delete);
        recur(node->right,false,res,to_delete);
        if (isRoot) res.push_back(node);
        return;
    }
};
