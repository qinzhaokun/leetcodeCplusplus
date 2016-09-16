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
    int maxPathSum(TreeNode* root) {
        int ret = INT_MIN;
        find(root,ret);
        return ret;
    }
    
    int find(TreeNode* root, int &ret){
        if(root){
            int sum = root->val;
            int l = find(root->left,ret);
            int r = find(root->right,ret);
            int t = max(l,r);
            if(t > 0) sum +=t;
            ret = max(ret,sum);
            ret = max(ret,root->val+l+r);
            return sum;
        }
        else{
            return 0;
        }
    }
};
