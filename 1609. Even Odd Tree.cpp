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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>qu;
        qu.push(root);
        int level=0;
        while(!qu.empty())
        {
            int size=qu.size();
            int prev=-1;
            for(int i=0;i<size;i++)
            {
                TreeNode* temp=qu.front();qu.pop();
                if(temp->left) qu.push(temp->left);
                if(temp->right) qu.push(temp->right);
                if(level%2==0)
                {
                    if(temp->val%2==0) return false;
                    if(temp->val<=prev) return false;
                }
                else
                {
                    if(temp->val%2==1) return false;
                    if(prev>0 && temp->val>=prev) return false;
                }
                prev=temp->val;
            }
            level++;
        }
        return true;
    }
};
