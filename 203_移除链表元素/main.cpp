#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
 * 双指针
 * 一个指针用来存有效节点
 * 另一个指针用来遍历节点
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;

        ListNode *dummy = new ListNode(-1); // 头部空节点
        ListNode *pPrev = dummy;            // 有效节点指针
        ListNode *pNode = head;             // 遍历指针
        while (pNode!=nullptr){
            if(pNode->val!=val){
                pPrev->next = pNode;
                pPrev = pNode;
            }
            pNode = pNode->next;
        }
        pPrev->next = nullptr;  // 注意将最后一个有效节点next指向空节点
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