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
    void reorderList(ListNode* head) {
        ListNode *ptr=head;
        if(head==NULL || head->next==NULL) return ;
        vector<ListNode *> v;
        while(ptr!=NULL)
    {
        v.push_back(ptr);
        ptr=ptr->next;
    }
    int n=v.size();
    for(int i=0;i<ceil(n/2);i++)
    {
        ListNode *temp=v[i]->next;
        v[i]->next=v[n-i-1];
        v[n-i-1]->next=temp;
    }
    v[n/2]->next=NULL;
    head=v[0];
    return ;
        
    }
};
