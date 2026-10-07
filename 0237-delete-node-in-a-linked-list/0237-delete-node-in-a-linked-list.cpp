/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        //1 way - Copies the next node’s value and next pointer into the current node, effectively removing the current node’s value from the list.
        // *node= *node->next; 

        // 2 way - Copy value of next node to deleting node and set next of node to node->next->next
        node->val = node->next->val;
        node->next = node->next->next;
    }
};