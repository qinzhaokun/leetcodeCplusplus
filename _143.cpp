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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;
        ListNode* fast = head;
        ListNode*slow = head;
        ListNode*last = NULL;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            last = slow;
            slow = slow->next;
        }
        //even
        if(fast == NULL){
            //split
            last->next = NULL;
        }
        //odd
        else{
            last = slow;
            slow = slow->next;
            last->next = NULL;
        }
        
        //reverse
        fast = slow->next;
        slow ->next = NULL;
        while(fast != NULL){
            ListNode* next = fast->next;
            fast->next = slow;
            slow = fast;
            fast = next;
        }
        
        fast = head;
        while(fast !=NULL){
            ListNode* next = fast->next;
            fast->next = slow;
            
            if(slow != NULL){
                ListNode* next2 = slow->next;
                slow->next = next;
                slow = next2;
            }
            fast = next;
            
        }
        
        
    }
};
