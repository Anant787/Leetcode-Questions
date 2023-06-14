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
void solve(TreeNode* root,vector<int>&temp){
         if(root==NULL) return ;
         solve(root->left,temp);
         temp.push_back(root->val);
         solve(root->right,temp);
}
    int getMinimumDifference(TreeNode* root) {
        vector<int>temp;
        solve(root,temp);
        int mini=INT_MAX;
        if(temp.size()==2) return temp[1]-temp[0];
        for(int i=0;i<temp.size();i++){
            for(int j=0;j<temp.size()-1;j++){
                if(i==j) continue;
                mini=min(mini,abs(temp[i]-temp[j]));
            }
        }
        return mini;
    }
};
