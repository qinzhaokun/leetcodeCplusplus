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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ret;
        if(root != NULL){
            s.push(root);
        }
        TreeNode* pre = NULL;
        while(!s.empty()){
            TreeNode* top = s.top();
            if((top->left == NULL && top->right == NULL) || (top->left != NULL && top->left == pre) || (top->right != NULL && top->right == pre)){
                ret.push_back(top->val);
                s.pop();
                pre = top;
            }
            else{
                if(top->right != NULL) s.push(top->right);
                if(top->left != NULL) s.push(top->left);
            }
        }
        return ret;
    }
};
