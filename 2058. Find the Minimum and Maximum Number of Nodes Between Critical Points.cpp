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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* ptr = head;
        ListNode* prev = NULL;
        int pr = 0;
        int cu = 0;
        int count = 1;
        vector<int> ans(2, -1);

        while (ptr) {
            prev = ptr;
            ptr = ptr->next;
            count++;
            if (ptr && ptr->next) {
                int ptrVal = ptr->val;
                int prevVal = prev->val;
                int nextVal = ptr->next->val;
                if ((ptrVal > prevVal && ptrVal > nextVal) || (ptrVal < prevVal && ptrVal < nextVal)) {
                    pr = cu;
                    cu = count;
                    if (pr) {
                        if (ans[0] != -1)
                            ans[0] = min(ans[0], cu - pr);
                        else
                            ans[0] = cu - pr;
                        if (ans[1] != -1)
                            ans[1] += cu - pr;
                        else
                            ans[1] = cu - pr;
                    }
                }
            }
        }

        return ans;
    }
};
