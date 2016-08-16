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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode newHead(0);
        newHead.next = head;
        
        ListNode* cur = &newHead;
        while(true){
            int i = 0;
            ListNode* tmp = cur;
            while(tmp && i < k){
                tmp = tmp->next;
                i++;
            }
            if(i == k && tmp){
                //start reverse
                ListNode* next = tmp->next;
                
                ListNode* p1 = cur->next;
                ListNode* p2 = p1->next;
                ListNode* p3 = next;
                while(p2 != next){
                    ListNode* nn = p2->next;
                    p2->next = p1;
                    p1->next = p3;
                    p3 = p1;
                    p1 = p2;
                    p2 = nn;
                }
                ListNode* newLast = cur->next;
                //cur->next->next = next;
                cur->next = tmp;
                cur = newLast;
            }
            else{
                break;
            }
        }
        
        return newHead.next;
    }
};
