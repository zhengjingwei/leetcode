#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next || k<2) return head;

        ListNode *pNode = head;
        ListNode *dummy = new ListNode(-1);
        ListNode *pPrev = dummy;
        dummy->next = head; // 避免k>链表长度的情况
        while (pNode){
            int i = 2;
            ListNode *pBegin = pNode;       // 该组第一个节点
            ListNode *pEnd = pNode->next;   // 该组最后节点

            while(pEnd && i < k){
                pEnd = pEnd->next;
                ++ i;
            }
            if (!pEnd) break;               // 不足k个不反转
            ListNode *pNext = pEnd->next;
            reverseCore(pPrev,pNext, pBegin, pEnd);
            pPrev = pBegin;
            pNode = pNext;
        }
        return dummy->next;
    }

private:
    // 左边相连节点/右边相连节点/区间开始节点/区间结束节点
    void reverseCore(ListNode *left, ListNode *right, ListNode *begin, ListNode *end){
        ListNode *pNode = begin;
        ListNode *pPrev = nullptr;
        while (pNode!=right){
            ListNode *pNext = pNode->next;
            pNode->next = pPrev;
            pPrev = pNode;
            pNode = pNext;
        }

        left->next = pPrev;     // 与左边连接
        begin->next = right;    // 与右边连接
    }
};


ListNode *createList(vector<int> nums){
    ListNode *head = new ListNode(nums[0]);
    ListNode *pPrev = head;
    for (int i = 1; i < nums.size(); ++i) {
        ListNode *node = new ListNode(nums[i]);
        pPrev->next = node;
        pPrev = node;
    }
    return head;
}

int main(){
//    vector<int> nums1 = {1,2,3,4,5}; // 1 5 2 4 3
    vector<int> nums1 = {1,2,3,4,5}; // 1 5 2 4 3
    ListNode *head1 = createList(nums1);
    Solution sol;
    ListNode *ret = sol.reverseKGroup(head1,2);
    while(ret!= nullptr){
        cout <<ret->val<<" ";
        ret = ret->next;
    }
    return 0;
}