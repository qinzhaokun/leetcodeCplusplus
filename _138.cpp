/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *cur = head;
        map<RandomListNode*,RandomListNode*> m;
        RandomListNode* vituralHead = new RandomListNode(0);
        RandomListNode* cur2 = vituralHead;
        while(cur != NULL){
            RandomListNode* now = new RandomListNode(cur->label);
            cur2->next = now;
            m[cur] = now;
            cur = cur->next;
            cur2 = now;
        }
        
        cur= head;
        cur2 = vituralHead->next;
        while(cur != NULL){
            if(cur->random != NULL)
                cur2->random = m[cur->random];
            cur = cur->next;
            cur2 = cur2->next;
        }
        
        return vituralHead->next;
    }
};
