class Solution {
public:

    TreeNode* helper(TreeNode* root){

        if(root->left == NULL)
            return root->right;

        if(root->right == NULL)
            return root->left;


        TreeNode* rightChild = root->right;

        TreeNode* lastRight = root->left;


        while(lastRight->right != NULL){
            lastRight = lastRight->right;
        }


        lastRight->right = rightChild;


        return root->left;
    }


    TreeNode* deleteNode(TreeNode* root, int key) {
        

        if(root == NULL)
            return NULL;


        // if root itself is key
        if(root->val == key)
            return helper(root);


        TreeNode* curr = root;


        while(curr != NULL){


            if(key < curr->val){

                // DON'T move first
                if(curr->left != NULL 
                   && curr->left->val == key){

                    curr->left = helper(curr->left);
                    break;
                }

                else{
                    curr = curr->left;
                }
            }


            else{

                if(curr->right != NULL 
                   && curr->right->val == key){

                    curr->right = helper(curr->right);
                    break;
                }

                else{
                    curr = curr->right;
                }
            }
        }


        return root;
    }
};