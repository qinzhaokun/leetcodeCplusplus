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
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0;
        ListNode* cur = head;
        ListNode* last = NULL;
        while(cur){
            n++;
            last = cur;
            cur = cur->next;
        }
        if(n == 0 || k%n == 0) return head;
        k %= n;
        
        cur = head;
        for(int i = 0;i < k;i++) cur = cur->next;
        
        ListNode* start = head;
        while(cur != last){
            cur = cur->next;
            start = start->next;
        }
        ListNode* newHead = start->next;
        start->next = NULL;
        last->next = head;
        return newHead;
    }
};
