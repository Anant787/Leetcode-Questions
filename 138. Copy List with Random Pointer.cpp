class Solution {
public:
    //Striver Approach DSA 450
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
        Node* temp = head;
        while(temp) {
            Node* next = temp->next;
            temp->next = new Node(temp->val);
            temp->next->next = next;
            temp = next;
        }
        temp = head;
        while(temp) {
            if(temp->random)
                temp->next->random = temp->random->next;
            else
                temp->next->random = NULL;
            temp = temp->next->next;
        }
        // Removing the first duplicates.
        temp = head->next;
        Node* curr = head;
        Node* ans = head->next;

        while(curr && temp) {
            // For original nodes
            if(curr->next)
                curr->next = curr->next->next;
            // For copied nodes
            if(temp->next)
                temp->next = temp->next->next;
            curr = curr->next;
            temp = temp->next;
        }
        return ans;
    }
};
