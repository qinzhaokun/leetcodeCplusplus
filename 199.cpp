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
    vector<int> rightSideView(TreeNode* root) {
        TreeNode* now = root;
        vector<int> ret;
        queue<TreeNode*> q;
        if(now !=NULL)
            q.push(now);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0;i < size;i++){
                TreeNode* top = q.front();
                q.pop();
                if(top->left !=NULL) q.push(top->left);
                if(top->right != NULL) q.push(top->right);
                if(i == size-1) ret.push_back(top->val);
            }
        }
        return ret;
    }
};
