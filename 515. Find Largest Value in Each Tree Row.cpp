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
    vector<int> ans;   // Global declare

    void solve(TreeNode* root,int lvl)
    {
        if(!root) return ;

        //checking if the size of vector is same as 
        // level then simply push else update with maximum
        if(ans.size() == lvl) ans.push_back(root->val);
        else ans[lvl] = max(ans[lvl],root->val);

        solve(root->left,lvl+1);
        solve(root->right,lvl+1);

    }
    vector<int> largestValues(TreeNode* root) {
        solve(root,0);

        return ans;       //return from global var
        
    }
};
