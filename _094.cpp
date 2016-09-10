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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        if(root){
            s.push(root);
            while(s.top()->left != NULL){
                s.push(s.top()->left);
            }
        }
        vector<int> ret;
        while(!s.empty()){
            TreeNode* node = s.top();
            ret.push_back(node->val);
            s.pop();
            if(node->right){
                s.push(node->right);
                while(s.top()->left != NULL){
                s.push(s.top()->left);
                }
            }
        }
        
        return ret;
    }
};
