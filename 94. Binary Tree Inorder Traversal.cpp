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
    vector<int> inorderTraversal(TreeNode* root) {
        
        // stack<TreeNode*>st;
        // TreeNode *node =root;
        // vector<int>inorder;
        
        // while(true)
        // {
        //     if(node!=NULL)
        //     {
        //         st.push(node);
        //         node=node->left;
        //     }
        //     else{
        //         if(st.empty()==true)
        //             break;
                
        //         node=st.top();
        //         st.pop();
        //         inorder.push_back(node->val);
        //         node=node->right;
        //     }
        // }
        // return inorder;
          
            //Recursive approach
        
//         vector<int>nodes;
//         inorder(root,nodes);
//         return nodes;
//     }
    
//     void inorder(TreeNode* root,vector<int>&nodes)
//     {
//         if(!root)
//         {
//             return ;
//         }
        
//         inorder(root->left,nodes);
//         nodes.push_back(root->val);
//         inorder(root->right,nodes);

    //Morries Travesal
    vector<int>inorder;
    TreeNode*cur = root;
    while(cur!=NULL)
    {
        if(cur->left ==NULL)
        {
            inorder.push_back(cur->val);
            cur = cur->right;
        }
        else
        {
            TreeNode*prev = cur->left;
            while(prev->right && prev->right !=cur)
            {
                prev = prev->right;
            }
            if(prev->right == NULL)
            {
                prev->right = cur;
                cur = cur->left;
            }
            else{
                prev->right = NULL;
                inorder.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
        return inorder;
    }
};
