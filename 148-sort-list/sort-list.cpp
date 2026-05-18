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

    // Find middle node
    ListNode* findMiddle(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL && fast->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    // Merge two sorted lists
    ListNode* merge(ListNode* left, ListNode* right) {

        ListNode dummy(0);

        ListNode* temp = &dummy;

        while(left != NULL && right != NULL) {

            if(left->val <= right->val) {

                temp->next = left;
                left = left->next;
            }

            else {

                temp->next = right;
                right = right->next;
            }

            temp = temp->next;
        }

        if(left != NULL) {
            temp->next = left;
        }

        if(right != NULL) {
            temp->next = right;
        }

        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {

        // Base case
        if(head == NULL || head->next == NULL) {
            return head;
        }

        // Find middle
        ListNode* mid = findMiddle(head);

        ListNode* rightHead = mid->next;

        mid->next = NULL;

        // Divide
        ListNode* left = sortList(head);
        ListNode* right = sortList(rightHead);

        // Merge
        return merge(left, right);
    }
};