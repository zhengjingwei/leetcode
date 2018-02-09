#include <iostream>
#include <stdlib.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n){
        ListNode *p = head;
        ListNode HEAD(0);
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


int main()
{
    ListNode L1(1);
    ListNode L2(2);
    L1.next = &L2;
    ListNode L3(3);
    L2.next = &L3;
    ListNode L4(4);
    L3.next = &L4;
    ListNode L5(5);
    L4.next = &L5;
    for(ListNode *p=&L1;p!=NULL;p=p->next){
        cout<< p->val<< " -> ";
    }
    Solution ans;
     for(ListNode *p=ans.removeNthFromEnd(&L1,2);p!=NULL;p=p->next){
        cout<< p->val<< " -> ";
    }
//    cout<<ans.lengthOfLongestSubstring(ss)<<endl;
    return 0;
}

