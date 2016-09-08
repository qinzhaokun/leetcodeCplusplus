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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n) return head;
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        
        ListNode* bef = newHead;
        for(int i = 0;i < m-1;i++){
            bef = head;
            head = head->next;
        }
        ListNode* saveHead = head;
        ListNode* cur = head->next;
        head->next = NULL;
        int i = 0;
        while(i < n-m){
            ListNode *tmp = cur->next;
            cur->next = head;
            head = cur;
            cur = tmp;
            i++;
        }
        bef->next = head;
        saveHead->next = cur;
        return newHead->next;
    }
};
