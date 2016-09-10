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
    vector<TreeNode*> generateTrees(int n) {
        return gen(1,n);
    }
    
    vector<TreeNode*> gen(int i,int j){
        vector<TreeNode*> ret;
        
        for(int k = i;k <= j;k++){
            vector<TreeNode*> left = gen(i,k-1);
            vector<TreeNode*> right = gen(k+1,j);
            if(left.size() == 0) left.push_back(NULL);
            if(right.size() == 0) right.push_back(NULL);
            for(int il = 0;il < left.size();il++){
                for(int ir = 0;ir < right.size();ir++){
                    TreeNode* node = new TreeNode(k);
                    node->left = left[il];
                    node->right = right[ir];
                    ret.push_back(node);
                }
            }
        }
        
        return ret;
    }
};
