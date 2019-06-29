class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || n <= 0) return head;
        ListNode *headNode = new ListNode(-1);
        ListNode *fast = head;          // 快指针
        ListNode *slow = head;          // 慢指针
        ListNode *prev = nullptr;       // 慢指针前一个节点
        for (int i = 0; fast && i < n; ++i)
            fast = fast->next;          // 快指针先走n步
        if(!fast) return head->next;    // 删除的是头结点
        while (fast){                   // 当快指针走到空，则慢指针指向导师第k个节点
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        prev->next = slow->next;        // 删除节点
        return head;
    }
};