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
    int findBottomLeftValue(TreeNode* root) {
        //level order traversal and then get the left most element
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<vector<int>>v;
        vector<int>ans;

        while(!q.empty()){
            TreeNode*temp=q.front();
            q.pop();

            if(temp==NULL){
                v.push_back(ans);
                if(!q.empty()){
                    q.push(NULL);
                    ans.clear();
                }
            }
            else{
                ans.push_back(temp->val);
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
        //we need vector ke last ka first element
        int n=v.size();
        return v[n-1][0];
    }
};
