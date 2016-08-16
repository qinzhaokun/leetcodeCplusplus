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
    ListNode* swapPairs(ListNode* head) {
        ListNode newHead(0);
        newHead.next = head;
        ListNode* last = &newHead;
        ListNode* cur = head;
        while(cur && cur->next){
            ListNode* next = cur->next->next;
            last->next = cur->next;
            cur->next->next = cur;
            cur->next = next;
            last = cur;
            cur = next;
        }
        return newHead.next;
    }
};
