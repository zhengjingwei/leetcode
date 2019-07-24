// 递归
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        if(l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

// 迭代
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        ListNode *head = l1->val < l2->val ? l1:l2;
        ListNode *p1 = l1, *p2 = l2;

        if(l1->val <= l2->val){
            head = p1;
            p1 = p1->next;
        }else{
            head = p2;
            p2 = p2->next;
        }
        ListNode *pPrev = head;  // 上次比较时值较小的节点
        while(p1 && p2){
            if(p1->val <= p2->val){
                pPrev->next = p1;
                pPrev = pPrev->next;
                p1 = p1->next;
            } else{
                pPrev->next = p2;
                pPrev = pPrev->next;
                p2 = p2->next;
            }
        }
        if(!p1)
            pPrev->next = p2;
        if(!p2)
            pPrev->next = p1;
        return head;
    }
};