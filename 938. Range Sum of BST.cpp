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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL)
        {
            return 0;
        }
        //If value is in Range, calculate the sum
        if(root->val >=low  && root->val <= high)
        {
            return root->val + rangeSumBST(root->left,low,high) + rangeSumBST(root->right,low,high);
        }
        //if low value is less,then there is no need to find it in left side go to right
        else if(root->val < low)
        {
           return rangeSumBST(root->right,low,high);
        }

        //if high value is greater than the range ,go to its left
        else
        {
           return rangeSumBST(root->left,low,high);
        }
        
    }
};
