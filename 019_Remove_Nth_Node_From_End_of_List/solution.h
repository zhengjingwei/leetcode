/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n){
        ListNode *p = head;
        ListNode HEAD(0); //pre Node
        HEAD.next=head;
        ListNode *q;
        int len = 0;
        while(p!=NULL){
            len++;
            p=p->next;
        }
        if(len ==1) {
            return NULL;
        }
        p=&HEAD;
        q=p->next;
        for(int i=0;i<len-n;i++){
            p=p->next;
            q=q->next;
        }
        p->next =q->next;
        free(q);
        return HEAD.next;
    }
};