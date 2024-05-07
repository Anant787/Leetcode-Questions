/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void doubl(ListNode* root, int& carry) {
        if (root == nullptr) {
            return;
        }
        //Traverse to the last Node
        doubl(root->next,carry);
        //Updating the value
        int newVal = (2 * root->val + carry) % 10;
        carry = (2 * root->val + carry) / 10;
        root->val = newVal;
    }

    ListNode* doubleIt(ListNode* head) {
        int carry=0;
        doubl(head,carry);
        // if carry exist then newNode.
            if (carry > 0) {
                ListNode* newNode = new ListNode(carry);
                newNode->next = head;
                head = newNode;
            }        
        return head;
    }
};
