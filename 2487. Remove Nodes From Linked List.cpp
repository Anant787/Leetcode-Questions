class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* tmp = head;

        vector<int> values;

        while (tmp)
        {
            values.push_back(tmp->val);
            tmp = tmp->next;
        }

        int largest = values[values.size() - 1];

        vector<bool> toDelete(values.size(), true);

        for (int i = values.size() - 1; i >= 0; --i)
        {
            if (largest <= values[i])
            {
                toDelete[i] = false;
                largest = values[i];
            }
        }

        int index = 0;

        while (toDelete[index++])
        {
            head = head->next;
        }

        tmp = head;

        while (index < values.size())
        {
            if (toDelete[index])
            {
                ListNode* newNext = tmp->next->next;
                tmp->next->next = nullptr;
                tmp->next = newNext;
            }
            else
            {
                tmp = tmp->next;
            }

            index += 1;
        }

        return head;
    }
};
