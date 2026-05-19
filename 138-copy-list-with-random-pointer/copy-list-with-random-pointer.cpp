/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head == NULL) return NULL;

        Node* temp = head;

        // Step 1: Insert copy nodes in between
        while(temp) {
            Node* copyNode = new Node(temp->val);

            copyNode->next = temp->next;
            temp->next = copyNode;

            temp = copyNode->next;
        }

        // Step 2: Copy random pointers
        temp = head;

        while(temp) {
            if(temp->random != NULL) {
                temp->next->random = temp->random->next;
            }

            temp = temp->next->next;
        }

        // Step 3: Separate original and copied list
        temp = head;
        Node* dummy = new Node(-1);
        Node* copy = dummy;

        while(temp) {
            copy->next = temp->next;
            temp->next = temp->next->next;

            copy = copy->next;
            temp = temp->next;
        }

        return dummy->next;
    }
};