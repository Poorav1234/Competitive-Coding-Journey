class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* temp = &dummy;

        while(temp->next != nullptr && temp->next->next != nullptr) {
            ListNode* first = temp->next;
            ListNode* second = temp->next->next;

            first->next = second->next;
            second->next = first;
            temp->next = second;

            temp = first;
        }

        return dummy.next;
    }
};