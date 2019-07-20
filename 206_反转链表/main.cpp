class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *pNode = head;
        ListNode *pPrev = nullptr;
        ListNode *pReversedHead = nullptr;
        while (pNode!= nullptr){
            ListNode *pNext = pNode->next;
            if(pNext == nullptr)
                pReversedHead = pNode;
            pNode->next = pPrev;
            pPrev = pNode;
            pNode = pNext;
        }
        return pReversedHead;
    }
};