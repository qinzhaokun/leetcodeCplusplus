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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*> s;
        queue<TreeNode*> q;
        vector<vector<int>> ret;
        if(root){
            q.push(root);
        }
        
        while(!q.empty() || !s.empty()){
            if(!q.empty()){
                vector<int> tmp;
                while(!q.empty()){
                    TreeNode* node = q.front();
                    q.pop();
                    tmp.push_back(node->val);
                    if(node->left) s.push(node->left);
                    if(node->right) s.push(node->right);
                }
                ret.push_back(tmp);
            }
            else{
                vector<int> tmp;
                pushToQueue(q,s,tmp);
                ret.push_back(tmp);
            }
        }
        
        return ret;
    }
    
    void pushToQueue(queue<TreeNode*> &q, stack<TreeNode*> &s, vector<int> &ret){
        if(!s.empty()){
            TreeNode* node = s.top();
            s.pop();
            ret.push_back(node->val);
            pushToQueue(q,s,ret);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
};
