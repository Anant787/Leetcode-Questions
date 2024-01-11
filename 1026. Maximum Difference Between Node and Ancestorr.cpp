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
    int solve(TreeNode*root,int maxNum,int minNum)
    {
        if(root==NULL)
        {
            return maxNum-minNum;      //diff if null
        }

        maxNum = max(root->val,maxNum);  //store max value in the path
        minNum = min(root->val,minNum);  //store min value in the path

        //find max diff. on traversing every path(left or right) 

        return max(solve(root->left,maxNum,minNum),solve(root->right,maxNum,minNum) );
    }
    int maxAncestorDiff(TreeNode* root) {
        int maxNum = 0;
        int minNum = 100000;

        return solve(root,maxNum,minNum);
        
    }
};
