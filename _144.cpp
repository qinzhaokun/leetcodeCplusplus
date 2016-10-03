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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ret;
        if(root == NULL) return ret;
        while(root != NULL || !s.empty()){
            while(root != NULL){
                s.push(root);
                ret.push_back(root->val);
                root = root->left;
            }
            root = s.top();
            s.pop();
            root = root->right;
        }
        return ret;
    }
    
};
