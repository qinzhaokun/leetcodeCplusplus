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
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = NULL;
        ListNode* first = sortList(head);
        ListNode* second = sortList(fast);
        
        ListNode *v = new ListNode(0);
        ListNode *h = v;
        while(first != NULL || second != NULL){
            if(first == NULL){
                v->next = second;
                second = second->next;
            }
            else if(second == NULL){
                v->next = first;
                first = first->next;
            }
            else{
                if(first->val <= second->val){
                  v->next = first;
                  first = first->next;  
                }
                else{
                    v->next = second;
                    second = second->next;
                }
            }
            v = v->next;
        }
        return h->next;
    }
};
