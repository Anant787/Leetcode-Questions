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
    int pairSum(ListNode* head) {

        vector<int>v;  //vector to store the linked list 

        while(head!=NULL)  //push the element of LL into the vector
        {
            v.push_back(head->val);
            head = head->next;
        }

        int n = v.size();  //size of vector
        int maxsum = 0;   //to calculate the max sum

        for(int i = 0 ;i<n/2;i++)   //for twins, iterate half of vector
        {
            maxsum = max(maxsum , v[i]+v[n-1-i]);   //max twins sum  
        }
        
        return maxsum;
        
    }
};
