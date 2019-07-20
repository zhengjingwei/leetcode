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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head || !head->next || m >= n) return head;
        ListNode *pNode = head;
        ListNode *pPrev = nullptr;

        int i = 1;
        while(pNode!= nullptr && i <m){
            pPrev = pNode;
            pNode = pNode->next;
            i++;
        }
        ListNode *con = pPrev;      // 前半部分末尾节点
        ListNode *tail = pNode;     // 待翻转的第一个节点，也是翻转后的最后一个节点

        // 中间部分翻转
        while (pNode != nullptr && i <= n){
            ListNode *pNext = pNode->next;
            pNode->next = pPrev;
            pPrev = pNode;
            pNode = pNext;
            i++;
        }
        if(con)
            con->next = pPrev;
        else
            head = pPrev;           // pPrev是翻转后的第一个节点

        tail->next = pNode;         // 翻转部分的最后一个节点和下一个节点相接
        return head;
    }
};

class SolutionI {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head || !head->next || m >= n) return head;
        ListNode *pNode = head;
        ListNode *pPrev = nullptr;

        while(m>1){
            pPrev = pNode;
            pNode = pNode->next;
            m--, n--;
        }
        ListNode *con = pPrev, *tail = pNode;    // 前半部分末尾节点

        // 中间部分迭代翻转
        while (n>0){
            ListNode *pNext = pNode->next;
            pNode->next = pPrev;
            pPrev = pNode;
            pNode = pNext;
            --n;
        }

        if(con != nullptr)
            con->next = pPrev;
        else
            head = pPrev;

        tail->next = pNode;
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
    vector<int> nums = {1,2,3,4,5};
    ListNode *head = createList(nums);
    Solution sol;
    ListNode *ret = sol.reverseBetween(head,2,4);
    while(ret!= nullptr){
        cout <<ret->val<<" ";
        ret = ret->next;
    }
    return 0;
}