class Solution {
public:
    TreeNode *check(int i,int j,vector<int>&v)
    {
        if(i>j)
        {
            return NULL;
        }

        int mid = i + (j-i)/2;   //mid element of vector

        TreeNode *root = new TreeNode(v[mid]);

        root->left = check(i,mid-1,v);
        root->right = check(mid+1,j,v);

        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        //convert list into vector
        vector<int>v;
        while(head)
        {
            v.push_back(head->val);
            head = head ->next;
        }

        //recursive binary search

        int i =0,j=v.size();

        return check(i,j-1,v);
    }
};
