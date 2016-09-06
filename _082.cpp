/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* vituralHead = new ListNode(0);
        vituralHead->next = head;
        ListNode* cur = head;
        ListNode* bef = vituralHead;
        while(cur){
            ListNode* tmp = cur;
            while(cur->next && cur->val == cur->next->val) cur = cur->next;
            if(tmp == cur){
                bef = cur;
            }
            else{
                bef->next = cur->next;
            }
            cur = cur->next;
        }
        return vituralHead->next;
    }
};
