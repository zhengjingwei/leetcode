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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *pNode = head;
        ListNode *dummy = new ListNode(-1); // 头部空节点
        ListNode *pPrev = dummy;            // 记录不重复元素的指针

        while (pNode!= nullptr){
            int cnt = 0;
            while (pNode->next && pNode->next->val == pNode->val){
                ++cnt;
                pNode = pNode->next;
            }
            if(cnt == 0){
                pPrev->next = pNode;
                pPrev = pNode;
            }
            pNode = pNode->next;
        }
        pPrev->next = nullptr;      // 当前pPrev是最后一个节点
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
    vector<int> nums = {1,1,2,3,3};
    ListNode *head = createList(nums);
    Solution sol;
    ListNode *ret = sol.deleteDuplicates(head);
    while(ret!= nullptr){
        cout <<ret->val<<" ";
        ret = ret->next;
    }
    return 0;
}