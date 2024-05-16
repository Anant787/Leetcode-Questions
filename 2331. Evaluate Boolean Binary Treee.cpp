
class Solution {
public:
    bool f(TreeNode* root){
        if(root->left==NULL && root->right==NULL) return root->val;
        int l=f(root->left);
        int r=f(root->right);
        if(root->val==2){
           return l||r;
        }
        return l&&r;

    }
    bool evaluateTree(TreeNode* root) {
        return f(root);
    }
};
