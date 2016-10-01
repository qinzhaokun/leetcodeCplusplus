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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        dfs(root,0,sum);
        return sum;
    }
    
    void dfs(TreeNode* node, int now, int &total){
        if(node){
            now = 10*now+node->val;
            if(node->left == NULL && node->right == NULL){
                total += now;
            }
            else{
                dfs(node->left, now, total);
                dfs(node->right,now,total);
            }
        }
    }
};
