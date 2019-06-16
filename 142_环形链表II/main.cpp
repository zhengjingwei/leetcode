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
    ListNode *detectCycle(ListNode *head) {
        if(!head || !(head->next) ) return nullptr;
        ListNode *fast = head;  // 快指针一次走2步
        ListNode *slow = head;  // 慢指针一次走1步
        do{
            fast = fast->next;
            if(fast) fast = fast->next;
            slow = slow->next;
        } while (fast!=nullptr && fast!=slow);
        // fast和slow在环内相遇; 则表示有环存在

        if(fast == nullptr && slow!=nullptr) return nullptr; // fast为空没有环
        
        // fast从头以相同步长遍历，相遇节点为第一个节点
        for(fast = head; fast!=slow;){
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};