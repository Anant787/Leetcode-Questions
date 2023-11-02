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
private:
    vector<int> solve(TreeNode* root, int& ans){
        if(!root) return vector<int>{0,0};
        
        int node = 1;
        
        int nodeVal = root->val;
        
        vector<int>left = solve(root->left, ans);
        vector<int>right = solve(root->right, ans);
        
        int totalNode = node + left[1] + right[1];
        int totalSum = nodeVal + left[0] + right[0];
        
        if(nodeVal==totalSum/totalNode){
            ans++;
        }
        return vector<int>{totalSum, totalNode};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        
        vector<int>a = solve(root, ans);
        
        return ans;
    }
};
