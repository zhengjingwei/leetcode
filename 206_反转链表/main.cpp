#include <iostream>
#include <bits/stdc++.h>
using namespace std;


struct ListNode {
    ListNode *next;
    int val;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
 * 将链表前半部分和后半部分分别存入两个容器
 * 比较容器内元素
 * 时间复杂度O(n) 空间复杂度O(n)
 */


///*
// * 用栈存储链表
// * 逐元素比较栈（逆序的链表）和原链表
// * 时间复杂度O(n) 空间复杂度O(n)
// */
//
//class Solution {
//public:
//    bool isPalindrome(ListNode* head) {
//        if(head == nullptr ) return false;
//        if(head->next == nullptr) return true;
//
//        stack<int> s;
//        ListNode *node = head;
//        while (node!= nullptr){
//            s.push(node->val);
//            node = node->next;
//        }
//
//        while(head!= nullptr){
//            if(head->val != s.top())
//                return false;
//            head = head->next;
//            s.pop();
//        }
//
//        return true;
//    }
//};

/*
 * 通过快慢指针确定中点
 * 将链表从中点分为两个链表，反转后半部分链表
 * 比较两个子链表的元素
 * 时间复杂度O(n) 空间复杂度O(1)
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;

        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *brk = head;

        // 确定中点
        while(fast && fast->next){
            fast = fast->next->next;
            brk = slow;
            slow = slow->next;
        }
        brk->next = nullptr;

        // 反转后半部分链表
        ListNode *pNode = slow->next;
        ListNode *pNext = nullptr;
        slow->next = nullptr;
        while(pNode){
            pNext = pNode->next;
            pNode->next = slow;
            slow = pNode;
            pNode = pNext;
        }

        // 顺序比较两个链表
        while(head){
            if(head->val != slow->val)
                return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
};
int main(){
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(2);
    ListNode *node4 = new ListNode(1);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    Solution sol;
    cout<< sol.isPalindrome(node1) << endl;

    return 0;
}

