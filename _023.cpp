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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists,0,lists.size()-1);
    }
    
    ListNode* mergeTwo(ListNode* node1, ListNode* node2){
        ListNode head(0);
        ListNode* cur = &head;
        while(node1 || node2){
            if(!node1){
                cur->next = node2;
                node2 = node2->next;
                cur = cur->next;
            }
            else if(!node2){
                cur->next = node1;
                node1 = node1->next;
                cur = cur->next;
            }
            else{
                if(node1->val <= node2->val){
                    cur->next = node1;
                    node1 = node1->next;
                    cur = cur->next;
                }
                else{
                    cur->next = node2;
                    node2 = node2->next;
                    cur = cur->next;
                }
            }
        }
        return head.next;
    }
    
    ListNode* merge(vector<ListNode*>& list1, int i, int j){
        if(i > j) return NULL;
        else if(i == j) return list1[i];
        else{
            int mid = i+(j-i)/2;
            ListNode* node1 = merge(list1,i,mid);
            ListNode* node2 = merge(list1,mid+1,j);
            return mergeTwo(node1,node2);
        }
    }
};
