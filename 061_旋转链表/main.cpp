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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k<=0) return head;
        ListNode* node = head;
        int len = 0;
        while(node!=nullptr){
            node = node->next;
            ++ len;     // 统计链表长度
        }
        
        k = k % len;    // 取余 避免重复多轮
        if (k == 0) return head;    // 刚好回到原地
        node = head;
        for(int i = 0; i< len - k-1;++i)
            node = node->next;
        
        ListNode* newHead = node->next; // 旋转后链表头
        node->next = nullptr;           // 新链表最后一个节点
        node = newHead;
        while(node->next!=nullptr) 
            node=node->next;            // 原链表最后节点
        node->next = head;              // 拼接链表
        return newHead;        
    }
};