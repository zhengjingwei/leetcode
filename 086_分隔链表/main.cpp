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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;
        ListNode *lHead = new ListNode(-1);
        ListNode *rHead = new ListNode(-1);
        ListNode *p = lHead;    // 小于x的指针
        ListNode *q = rHead;    // 大于等于x的指针
        while (head){
            if (head->val < x){
                p->next = head;
                p = head;
            }
            else{
                q->next = head;
                q = head;
            }
            head = head->next;
        }
        q->next = nullptr;      // 注意将最后一个节点指向空节点
        p->next = rHead->next;
        return lHead->next;
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
    vector<int> nums = {1,4,3,2,5,2};
    ListNode *head = createList(nums);
    Solution sol;
    ListNode *ret = sol.partition(head,3);
    while(ret!= nullptr){
        cout <<ret->val<<" ";
        ret = ret->next;
    }
    return 0;
}