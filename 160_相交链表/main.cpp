/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 如果存在交点，则两个链表从后往前数min(len1,len2)长度的链表，同时开始遍历
// 必然存在某两个节点值相等
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr) return nullptr;

        // 第一步：分别遍历两个链表得到链表长度
        ListNode *node1 = headA;
        ListNode *node2 = headB;
        int len1 = 0;
        int len2 = 0;
        while(node1!= nullptr){
            ++len1;
            node1 = node1->next;
        }
        while (node2!=nullptr){
            ++len2;
            node2 = node2->next;
        }
        
        // 第二步：如果较长链表为链表1，则链表1先走len1-len2步
        if(len1 > len2){
            for (int i = 0; i < len1-len2; ++i) {
                headA = headA->next;
            }
        }else if(len1 < len2){
            for (int i = 0; i < len2-len1; ++i) {
                headB = headB->next;
            }
        }
        
        // 第三步：同时遍历两个链表剩余元素
        while(headA!= nullptr){
            if(headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
};