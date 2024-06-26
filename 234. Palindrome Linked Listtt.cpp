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
    ListNode * reverseList(ListNode * head)
    {
        ListNode * prev = NULL;
        ListNode * next = NULL;

        while(head != NULL)
        {
            next = head->next;
            head->next = prev;
            prev = head ; 
            head = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
        {
            return true;
        }

        ListNode * slow = head;
        ListNode * fast = head;

        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next ;
            fast = fast->next->next;
        }

        slow -> next = reverseList(slow->next);
        slow = slow->next;

        while(slow != NULL)
        {
            if(head->val != slow->val)
            {
                return false;
            }

            head= head -> next;
            slow = slow->next;
        }

        return true;

        // 1-approach (Naive-wise)

        // vector<int> v ;
        // ListNode *temp = head ;
        // while(temp!=NULL){
        //     v.push_back(temp->val) ;
        //     temp = temp->next ;
        // }
        // int i , n = v.size(),j ;
        // i = 0 , j = n-1 ;
        // while(i<j){
        //     if(v[i]!=v[j]){
        //         return false ;
        //     }
        //     else{
        //         i++ ;
        //         j-- ;
        //     }
        // }
        // return true ;

    }
};
