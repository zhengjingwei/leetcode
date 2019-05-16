#include <iostream>
#include <bits/stdc++.h>
using namespace std;



struct ListNode {
    ListNode *next;
    int val;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
 * 归并排序O(nlogn)
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }


    ListNode* mergeSort(ListNode* head){
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *fast = head;  // 快指针走两步
        ListNode *slow = head;  // 慢指针走一步
        ListNode *brk = head;   // 断点，作为左链表的最后一个节点
        while(fast && fast->next){
            fast = fast->next->next;
            brk = slow;
            slow = slow->next;
        }
        brk->next = nullptr;
        ListNode *head1 = mergeSort(head);
        ListNode *head2 = mergeSort(slow);
        return mergeList(head1,head2);
    }


    // 设置快慢指针遍历；二分得到两个子链表
    ListNode* mergeList(ListNode *head1, ListNode *head2){
        if(head1 == nullptr) return head2;
        if(head2 == nullptr) return head1;
        if(head1->val < head2->val){
            head1->next = mergeList(head1->next,head2);
            return head1;
        } else{
            head2->next = mergeList(head1,head2->next);
            return head2;
        }
    }
};

int main(){
    ListNode *node1 = new ListNode(4);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(1);
    ListNode *node4 = new ListNode(3);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    Solution sol;
    ListNode *head = sol.sortList(node1);
    while(head!= nullptr){
        cout<<head->val<<" ";
        head = head->next;
    }

    return 0;
}

