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
    ListNode* partition(ListNode* head, int x) {
        //Easy to understand
        
        //list1 is for element smaller than x 
        //list2 is for element greater or equal than x

        ListNode * list1 = new ListNode(0);
        ListNode * list2 = new ListNode(0);

        //TWO iterting Pointers
        ListNode* l1 = list1;
        ListNode* l2 = list2;

        while(head)
        {
            if(head->val<x)         //Check the value is smaller than x
            {
                l1->next = head;       
                l1=l1->next;
            }
            else
            {
                l2->next = head;
                l2 = l2->next;
            }
            head = head ->next;
        }

        l1 ->next = list2 ->next;  //Combine List1 and List2
        l2->next = NULL;            //putting null at the end of List 2

        return list1->next;       //Return from head
    }
};
