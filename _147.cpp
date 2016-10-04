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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode *vituralHead = new ListNode(0);
        ListNode* last = head;
        vituralHead->next = head;
        ListNode* now = head->next;
        while(now != NULL){
            ListNode* tmp = vituralHead;
            ListNode* next = now->next;
            while(tmp->next->val < now->val) tmp = tmp->next;
            
            if(tmp->next != now){
                now->next = tmp->next;
                tmp->next = now;
                last->next = next;
            }
            else last = now;
            now = next;
            
        }
        return vituralHead->next;
    }
};
