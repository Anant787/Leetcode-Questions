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

    TreeNode* LCA(TreeNode* root, int startValue, int destValue){
        // finding LCA
        if(root==NULL || root->val==startValue || root->val==destValue){
            return root;
        }

        TreeNode* l = LCA(root->left,startValue,destValue);
        TreeNode* r = LCA(root->right,startValue,destValue);

        if(l==NULL) return r;
        if(r==NULL) return l;
        return root;
    }


    void dfs(TreeNode* root, int dest, string &ans, string &temp){
        // finding path
        if(root==NULL){
            return;
        }

        if(root->val==dest){
            ans=temp;
            return;
        }

        temp+='L';
        dfs(root->left,dest,ans,temp);
        temp.pop_back();

        temp+='R';
        dfs(root->right,dest,ans,temp);
        temp.pop_back();

    }

    string getDirections(TreeNode* root, int startValue, int destValue) {

        // finding Least common ancestor(LCA)
        TreeNode* lca = LCA(root,startValue,destValue);

        // path from lca to dest
        string lcatodest;
        string test="";
        dfs(lca,destValue,lcatodest,test);

        // path form lca to start
        string lcatostart;
        test="";
        dfs(lca,startValue,lcatostart,test);
        for(int i=0; i<lcatostart.size(); i++){
            lcatostart[i]='U';
        }

        // final path
        string finalpath = lcatostart+lcatodest;
        return finalpath;
    }
};
