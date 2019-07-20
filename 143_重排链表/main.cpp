#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
 * 分为三个步骤
 * （1）通过快慢指针找到链表中点，切割为左右两个链表
 * （2）将右链表进行翻转
 * （3）合并两个链表
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return;
        stack<ListNode*> st;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *head2 = slow->next;
        slow->next = nullptr;   // 找到中点

        // 翻转后半部链表
        head2 = reverseList(head2);

        // 合并两个链表
        mergeList(head, head2);
    }

private:
    // 翻转链表
    ListNode* reverseList(ListNode* head){
        if(!head || !head->next) return head;
        ListNode *pNode = head;
        ListNode *pPrev = nullptr;
        while (pNode){
            ListNode *pNext = pNode->next;
            pNode->next = pPrev;
            pPrev = pNode;
            pNode = pNext;
        }
        return pPrev;
    }
    // 合并链表
    void mergeList(ListNode* head1, ListNode *head2){
        ListNode *p1 = head1;
        ListNode *p2 = head2;
        while (p1 && p2){
            ListNode *p1Next = p1->next;
            ListNode *p2Next = p2->next;
            p1->next = p2;
            p2->next = p1Next;
            p1 = p1Next, p2 = p2Next;
        }
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
    vector<int> nums1 = {1,2,3,4}; // 1 5 2 4 3
    ListNode *head1 = createList(nums1);
    Solution sol;
    sol.reorderList(head1);
    ListNode *ret = head1;
    while(ret!= nullptr){
        cout <<ret->val<<" ";
        ret = ret->next;
    }
    return 0;
}