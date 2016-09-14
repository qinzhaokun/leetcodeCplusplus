/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) return;
        root->next = NULL;
        while(root){
            TreeLinkNode* node = root;
            while(node){
                if(node->left){
                    if(node->right) {
                        node->left->next = node->right;
                        node->right->next = getNext(node->next);
                    }
                    else{
                        node->left->next = getNext(node->next);
                    }
                }
                else if(node->right){
                    node->right->next = getNext(node->next);
                }
                node = node->next;
            }
            
            root = getNext(root);
        }
    }
    
    TreeLinkNode* getNext(TreeLinkNode* node){
        if(node == NULL) return node;
        if(node->left) return node->left;
        else if(node->right) return node->right;
        return getNext(node->next);
    }
};
