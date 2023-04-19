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
        int solve(TreeNode* root, bool isleft, int len)
    {
        if(root==NULL) return 0; // If the root is NULL, return 0 as there is no zigzag path

        int lh = solve(root->left,true, isleft?1:len+1); // Recursively calculate the zigzag length for the left child
        int rh = solve(root->right,false,isleft?len+1:1); // Recursively calculate the zigzag length for the right child

        return max(len,max(lh,rh)); // Return the maximum zigzag length between the left child, right child, and the current node
    }

    int longestZigZag(TreeNode* root) {
        if(root==NULL) return 0; // If the root is NULL, return 0 as there is no zigzag path

    int lh = solve(root->left,true,1); // Calculate the zigzag length for the left child
    int rh = solve(root->right,false,1); // Calculate the zigzag length for the right child

    return max(lh,rh); // Return the maximum zigzag length between the left child and the right child
        
    }
};
