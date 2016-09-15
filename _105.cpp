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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
    
    
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int i, int j, int s, int t){
        if(i == j){
            TreeNode* node = new TreeNode(preorder[i]);
            return node;
        }
        else if(i > j){
            return NULL;
        }
        else{
            TreeNode* node = new TreeNode(preorder[i]);
            int k = s;
            while(k <= t && inorder[k] != preorder[i]) k++;
            
            int l = k-s;
            node->left = dfs(preorder,inorder,i+1,i+l,s,k-1);
            node->right = dfs(preorder,inorder,i+l+1,j,k+1,t);
            return node;
        }
    }
};
