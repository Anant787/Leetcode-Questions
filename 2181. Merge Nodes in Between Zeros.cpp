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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* cur = head->next;
        ListNode* pre = head;
        ListNode* d = NULL;
        while(cur){
            if(cur->val!=0){
                pre->val+=cur->val;
            }
            else{
                d = pre;
                pre = pre->next;
                pre->val = 0;
            }
            cur = cur->next;
        }
        d->next = NULL;
        return head;

    }
};
