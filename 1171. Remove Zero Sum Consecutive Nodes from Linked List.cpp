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
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(head == NULL) return 0;
        ListNode* temp = new ListNode(0);
        temp->next = head;
        int prefix_sum= 0;
        unordered_map<int, ListNode*> mp;
        mp[0] = temp;
        while(head){
            prefix_sum += head->val;
            if(mp.find(prefix_sum) != mp.end()){
                ListNode* start = mp[prefix_sum];
                int sum = prefix_sum;
                while(start != NULL && start != head){
                    start = start->next;
                    sum += start->val;
                    if(start != head) mp.erase(sum);
                }
                mp[prefix_sum]->next = head->next;
            }
            else{
                mp[prefix_sum] = head;
            }
            head = head->next;
        }
        return temp->next;
    }
};
