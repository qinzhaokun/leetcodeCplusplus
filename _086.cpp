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
    ListNode* partition(ListNode* head, int x) {
        ListNode* head1 = new ListNode(0);
        ListNode* head2 = new ListNode(0);
        ListNode* cur1 = head1;
        ListNode* cur2 = head2;
        while(head){
            if(head->val < x){
                cur1->next = head;
                cur1 = head;
                head = head->next;
            }
            else{
                cur2->next = head;
                cur2 = head;
                head = head->next;
                cur2->next = NULL;
            }
        }
        
        if(head1->next){
            cur1->next = head2->next;
            return head1->next;
        }
        else{
            return head2->next;
        }
    }
};
