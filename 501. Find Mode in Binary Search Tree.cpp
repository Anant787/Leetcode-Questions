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
    vector<int>v;
    void traversal(TreeNode* root)   // inorder traversal
    {
        if(root!=nullptr){
            traversal(root->left);
            v.push_back(root->val);
            traversal(root->right);
        }
        else return ;
    }
    vector<int> findMode(TreeNode* root) {
        traversal(root);
        unordered_map<int,int>mp;
        int maxo =0;
        for(auto it : v){
            mp[it]++;
            maxo = max(maxo , mp[it]);
        }
        vector<int>ans;
        for(auto it : mp){
            if(it.second == maxo){
                ans.push_back(it.first);
            }
        }
        return ans;

    }
};
