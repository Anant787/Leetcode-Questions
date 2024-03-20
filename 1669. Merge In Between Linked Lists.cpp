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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* pre;
        ListNode* suf;
        ListNode* temp;
        temp=list1;
        for(int i=0; i<b; i++){
            if(i==a-1){
                pre=temp;
            }
            temp=temp->next;
        }
        suf=temp->next;
        temp=list2;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=suf;
        pre->next=list2;
        return list1;
    }
};
