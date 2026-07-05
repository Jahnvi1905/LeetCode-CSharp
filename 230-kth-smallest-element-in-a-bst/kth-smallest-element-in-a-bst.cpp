/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    vector<int> inorderTraversal(TreeNode* root) {
      vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        // Loop runs as long as there are nodes to visit OR elements in the stack
        while (curr != nullptr || !st.empty()) {
            
            // 1. Go as deep left as possible, caching parents on the stack
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }

            // 2. Current is now nullptr, so pop the last valid parent node
            curr = st.top();
            st.pop();

            // 3. Process the Node (Root step)
            ans.push_back(curr->val);

            // 4. Move to the right subtree
            curr = curr->right;
        }
        return ans;
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> sortedNodes = inorderTraversal(root);

        return sortedNodes[k-1];
    }
};