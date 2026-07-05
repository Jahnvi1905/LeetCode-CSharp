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

    bool check(TreeNode* root , long minValue , long maxValue){
        if(root == NULL){
            return true;
        }
        if(root->val < minValue || root->val > maxValue){
            return false;
        }

        bool left = check(root->left,minValue,(long)root->val-1);
        bool right = check(root->right,(long)root->val+1 , maxValue);

        return left&&right;
    }

    bool isValidBST(TreeNode* root) {
        return check(root,INT_MIN,INT_MAX);
    }
};