/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        flat(root);
    }
    
    TreeNode* flat(TreeNode* root){
        if(root){
            TreeNode* leftMost = NULL;
            TreeNode* rightMost = NULL;
            if(root->left){
                leftMost = flat(root->left);
            }
            if(root->right){
                rightMost = flat(root->right);
            }
            
            if(leftMost){
                TreeNode* tmp = root->right;
                root->right = root->left;
                leftMost->right = tmp;
                root->left = NULL;
            }
            
            if(rightMost) return rightMost;
            else if(leftMost) return leftMost;
            else return root;
        }
        else{
            return NULL;
        }
    }
};
