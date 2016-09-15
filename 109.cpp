/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head){
            return NULL;
        }
        if(head->next ==NULL){
            return new TreeNode(head->val);
        }
        ListNode* low = head;
        ListNode* fast = head;
        ListNode* lastLow = NULL;
        while(fast != NULL && fast->next != NULL){
            lastLow = low;
            low = low->next;
            fast = fast->next;
            fast = fast->next;
        }
        TreeNode* node = new TreeNode(low->val);

        lastLow->next = NULL;
        node->left = sortedListToBST(head);
        node->right = sortedListToBST(low->next);
        return node;
        
    }
};
