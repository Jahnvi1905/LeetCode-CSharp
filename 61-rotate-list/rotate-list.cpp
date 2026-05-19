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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL || head->next == NULL || k == 0)
            return head;
        
        // Find length and last node
        ListNode* tail = head;
        int len = 1;
        
        while(tail->next) {
            tail = tail->next;
            len++;
        }
        
        // Reduce k
        k = k % len;
        
        if(k == 0) return head;
        
        // Make circular list
        tail->next = head;
        
        // Find new tail
        int steps = len - k;
        ListNode* newTail = head;
        
        for(int i = 1; i < steps; i++) {
            newTail = newTail->next;
        }
        
        // New head
        ListNode* newHead = newTail->next;
        
        // Break circle
        newTail->next = NULL;
        
        return newHead;
    }
};