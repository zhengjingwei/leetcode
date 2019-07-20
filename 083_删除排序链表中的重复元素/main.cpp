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
        ListNode *pNode = head->next;
        ListNode *pPrev = head;
        while (pNode!= nullptr){
            while (pNode!= nullptr && pNode->val == pPrev->val)
                pNode = pNode->next;
            pPrev->next = pNode;
            pPrev = pNode;
            if(pNode) pNode = pNode->next;
        }

        return head;
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