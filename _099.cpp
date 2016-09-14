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
    TreeNode* node1;
    TreeNode* node2;
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> s;
        while(root) {
            s.push(root);
            root = root->left;
        }
        TreeNode* last = NULL;
        while(!s.empty()){
            TreeNode* now = s.top();
            s.pop();
            if(last){
                if(now->val < last->val){
                    if(!node1){
                        node1 = last;
                        node2 = now;
                    }
                    else{
                        node2 = now;
                    }
                }
            }
            last = now;
            if(now->right){
                s.push(now->right);
                while(s.top()->left){
                    s.push(s.top()->left);
                }
            }
        }
        if(node1){
            int tmp = node1->val;
            node1->val = node2->val;
            node2->val = tmp;
        }
    }
    
    
};

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
    TreeNode* node1;
    TreeNode* node2;
    void recoverTree(TreeNode* root) {
        node1 = NULL;node2 = NULL;
        TreeNode* last = NULL;
        while(root){
            if(root->left){
                TreeNode* tmp = root->left;
                while(tmp->right != NULL && tmp->right != root){
                    tmp = tmp->right;
                }
                if(tmp->right ==NULL) {
                    tmp->right = root;
                    root = root->left;
                }
                else{
                    tmp->right = NULL;
                    if(last){
                        if(last->val > root->val){
                            if(!node1){
                                node1 = last;node2 = root;
                            }
                            else{
                                node2 = root;
                            }
                            
                        }
                    }
                    last = root;
                    root = root->right;
                }
            }
            else{
                if(last){
                        if(last->val > root->val){
                            if(!node1){
                                node1 = last;node2 = root;
                            }
                            else{
                                node2 = root;
                            }
                            
                        }
                }
                last = root;
                root = root->right;
            }
        }
        
        if(node1){
            int tmp = node1->val;
            node1->val = node2->val;
            node2->val = tmp;
        }
    }
};
