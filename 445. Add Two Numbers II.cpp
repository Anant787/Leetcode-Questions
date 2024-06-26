class Solution {
    // by reversing 
    ListNode* reverseList(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(curr!=NULL){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *list1= reverseList(l1);
        ListNode *list2= reverseList(l2);
        int sum=0;
        int carry=0;
        ListNode* res=new ListNode();
        while(list1 or list2){
            if(list1){
                sum+=list1->val;
                list1=list1->next;
            }
            if(list2){
                sum+=list2->val;
                list2=list2->next;
            }
            res->val=sum%10;
            carry=sum/10;
            ListNode* head=new ListNode(carry);
            head->next=res;
            res=head;
            sum=carry;
        }
        return carry? res:res->next;
    }
};
