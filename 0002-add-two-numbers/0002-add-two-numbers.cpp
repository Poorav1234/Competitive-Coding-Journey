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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = l1;
        ListNode* prev = nullptr;
        int carry = 0;

        while(l1 != nullptr && l2 != nullptr){
            int v1 = l1->val;
            int v2 = l2->val;
            if(v1 + v2 + carry > 9) {
                l1->val = v1 + v2 + carry;
                l1->val %= 10;
                carry = 1;
            }
            else {
                l1->val = v1 + v2 + carry;
                carry = 0;
            }
            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        if(l2 != nullptr){
            prev->next = l2;
            l1 = l2;
        }

        while(l1 != nullptr){
            int v1 = l1->val;
            if(v1 + carry > 9) {
                l1->val = v1 + carry;
                l1->val %= 10;
                carry = 1;
            }
            else {
                l1->val = v1 + carry;
                carry = 0;
            }
            prev = l1;
            l1 = l1->next;
        }
        if(carry == 1){
            ListNode* node = new ListNode(carry, nullptr);
            prev->next = node;
        }
        return ans;
    }
};