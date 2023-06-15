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
    void maxLevel(TreeNode* root, map<int, int>& m, int h){
        if(root!=NULL) m[h]+=root->val;
        if(root->left!=NULL) maxLevel(root->left, m, h+1);
        if(root->right!=NULL) maxLevel(root->right, m, h+1);
    }

    int maxLevelSum(TreeNode* root) {

        map<int, int>m;
        maxLevel(root, m, 0);
        int max=INT_MIN, res=0;
        for(auto& i : m){
            if(i.second>max){
                res = i.first;
                max = i.second;
            }
        }
        return res+1;
        
        
        
        
        
        // BFS traversal

        // queue<TreeNode*>q;
        // q.push(root);
        // int maxi=root->val;
        // int level=1;
        // int ans=1;
        // while(!q.empty()){
        //     int n=q.size();
        //     int currSum=0;
        //     while(n--){
        //         TreeNode*node=q.front();
        //         currSum+=node->val;
        //         q.pop();

        //         if(node->left)
        //             q.push(node->left);
        //         if(node->right)
        //             q.push(node->right);
        //     }

        //     if(currSum>maxi){
        //         maxi=currSum;
        //         ans=level;
        //     }
        //     level++;
        // }
        // return ans;
        
    }
};
