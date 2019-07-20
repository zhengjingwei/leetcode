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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode *dummy = new ListNode(-1);
        ListNode *pNode = head->next;
        dummy->next = head;         // 将第一个节点插入
        head->next = nullptr;

        while (pNode!= nullptr){
            // 查找插入位置
            ListNode *pPrev = dummy;
            ListNode *pNext = pNode->next;
            while (pPrev->next!= nullptr && pPrev->next->val < pNode->val)
                pPrev = pPrev->next;    // 指向小于pNode的最大节点

            pNode->next = pPrev->next;
            pPrev->next = pNode;
            pNode = pNext;
        }

        return dummy->next;
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
    vector<int> nums1 = {4,2,1,3};
    ListNode *head1 = createList(nums1);
    Solution sol;
    ListNode *ret = sol.insertionSortList(head1);
    while(ret!= nullptr){
        cout <<ret->val<<" ";
        ret = ret->next;
    }
    return 0;
}