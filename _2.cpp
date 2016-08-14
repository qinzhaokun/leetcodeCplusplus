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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* it1 = l1;
        ListNode newHead(0);
        ListNode* it3 = &newHead;
        ListNode* it2 = l2;
        int addtional = 0;
        while(it1 || it2){
            int tmp  = addtional + (it1?it1->val:0) + (it2?it2->val:0);
            addtional = tmp/10;
            if(it1){
                it1->val = tmp%10;
                it3->next = it1;
            }
            else{
                it2->val = tmp%10;
                it3->next = it2;
            }
            if(it1) it1 = it1->next;
            if(it2) it2 = it2->next;
            it3 = it3->next;
        }
        if(addtional > 0){
            ListNode* last = new ListNode(addtional);
            it3-> next = last;
        }
        return newHead.next;
        
    }
};
