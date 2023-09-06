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
    int GetSize(ListNode*head)   //count the number of element or nodes
    {
        int count = 0;
        while(head)
        {
            head = head->next;
            count++;
        }
        return count;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int llsize = GetSize(head);

        int partsize = llsize / k;    //quotient
        int extraNode = llsize % k;   //rem

        vector<ListNode*>ans;
        ListNode *curr = head , *prev = NULL;

        while(head)
        {
            int eachpartsize = partsize; 
            ans.push_back(curr);

            while(eachpartsize > 0)  //first split
            {
                prev = curr;
                curr = curr ->next;
                eachpartsize--;
            }

            if(extraNode != 0 && curr != NULL)   //check for extra node
            {
                extraNode --;
                prev = curr;
                curr= curr->next;
            }

            if(prev!=NULL)   
            {
                head = curr;
                prev ->next = NULL;
            }
        }
        while(ans.size() != k)     //edge case of null values
        {
            ans.push_back(NULL);
        }

        return ans;
        
    }
};
