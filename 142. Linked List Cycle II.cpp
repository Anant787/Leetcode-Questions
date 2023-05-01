/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        if(head == NULL || head ->next ==NULL)
        {
            return NULL;
        }

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *entry = head;

        while(fast->next && fast ->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)       //find the collision node
            {
                while(slow != entry)   //find the starting point of cycle
                {
                    slow = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        return NULL;













        // ListNode* slow=head,*fast=head;
        // while(slow and fast){
        //     slow=slow->next;
        //     fast=fast->next;
        //     if(fast)fast=fast->next;
        //     if(slow==fast)break;
        // }
        // if(!slow or !fast)return NULL;
        // slow=head;
        // //If you move from head pointer and a pointer from the meeting point it will always meet, a+b=k(b+c)

        // while(slow!=fast){
        //     slow=slow->next;
        //     fast=fast->next;
        // }
        // return slow;

        // ListNode *slow,*fast;
        // slow = fast = head;

        // while(fast && fast ->next)
        // {
        //     slow = slow->next;
        //     fast = fast ->next ->next;

        //     if(slow == fast )
        //     {
        //         break;
        //     }
        // }

        // if(!fast || !fast->next)
        // {
        //     return NULL;
        // }

        // fast = head;

        // while(fast != slow)
        // {
        //     slow= slow->next;
        //     fast = fast->next;
        // }
        // return fast;
        
    }
};
