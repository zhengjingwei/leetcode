#include <iostream>
#include <bits/stdc++.h>
using namespace std;


struct ListNode {
    ListNode *next;
    int val;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
 * 时间复杂度O(n) 空间复杂度O(1)
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return head;
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *node = head->next->next;
        ListNode *headEven = even;

        // 分为奇数链表和偶数链表
        while (node && node->next){
            odd->next = node;
            even->next = node->next;
            node->next = nullptr;   // 防止最后一个奇数节点接到偶数节点
            node = even->next->next;
            odd = odd->next;
            even = even->next;
        }

        // 如果最后一个节点是奇数节点，需要额外处理
        if(node){
            odd->next = node;
            even->next = nullptr;
            odd = node;
        }
        // 拼接两个链表
        odd->next = headEven;
        return head;
    }
};


int main(){
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    Solution sol;
    ListNode *head = sol.oddEvenList(node1);
    while (head){
        cout<<head->val<<" ";
        head = head->next;
    }

    return 0;
}

