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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = head;
        ListNode newHead(0);
        newHead.next = cur;
        ListNode* last = &newHead;
        int i = 0;
        while(cur && i < n-1){
            cur = cur->next;
            i++;
        }
        cur = cur->next;
        
        while(cur){
            last = last->next;
            cur = cur->next;
        }
        last->next = last->next->next;
        return newHead.next;
    }
};
