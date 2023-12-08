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
    string ans;
    
    void constructString(TreeNode*root)
    {
        if(root==NULL)return;
        
        ans+=to_string(root->val);
        
        if(root->left==NULL && root->right==NULL)return;
        
        ans+="(";
        constructString(root->left);
        ans+=")";
        
        if(root->right!=NULL)
        {
            ans+="(";
            constructString(root->right);
            ans+=")";
            
        }
    }
public:
    string tree2str(TreeNode* root) {
        ans = "";
        constructString(root);
        return ans;
    }
};
