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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        vector<int> tmp;
        if(root){
            preorder(ret,root,sum,tmp);
        }
        
        return ret;
    }
    
    void preorder(auto& ret, TreeNode* node, int now, auto& tmp){
        now -= (node->val);
        if(!(node->left) && !(node->right)){
            if(now == 0){
                vector<int> copy(tmp);
                copy.push_back(node->val);
                ret.push_back(copy);
            }
        }
        else{
            tmp.push_back(node->val);
            if(node->left){
                preorder(ret,node->left,now,tmp);
            }
            if(node->right){
                preorder(ret,node->right,now,tmp);
            }
            tmp.pop_back();
        }
    }
};
