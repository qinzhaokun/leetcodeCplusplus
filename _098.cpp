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
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        
        return isV(root,LONG_MIN,LONG_MAX);
    }
    
    bool isV(TreeNode* node, long min1, long max1){
        if(min1 > max1 || node->val <= min1 || node->val >= max1) return false;
        bool left = true;
        bool right  = true;
        if(node->left){
            left = isV(node->left,min1,min((long)(node->val),max1));
        }
        if(node->right){
            right = isV(node->right,max(min1,(long)(node->val)),max1);
        }
        
        return left&&right;
    }
};
