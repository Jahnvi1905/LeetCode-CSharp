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
    ListNode* deleteMiddle(ListNode* head) {

        // Empty list or single node
        if(head == NULL || head->next == NULL) {
            return NULL;
        }

        int length = 0;

        ListNode* temp = head;

        // Find length
        while(temp != NULL) {

            length++;

            temp = temp->next;
        }

        int middle = length / 2;

        temp = head;

        // Move to node before middle
        for(int i = 1; i < middle; i++) {
            temp = temp->next;
        }

        // Delete middle node
        ListNode* nodeToDelete = temp->next;

        temp->next = temp->next->next;

        delete nodeToDelete;

        return head;
    }
};