#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
 * 用两个栈分别存储两个链表的翻转
 * 弹栈并进行求和，将每一位的求和结果插入链表头
 * 时间复杂度O（n）空间复杂度O（n）
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        stack<int> st1, st2;    // 用栈存储实现倒序
        while (l1){
            st1.push(l1->val);
            l1 = l1->next;
        }
        while (l2){
            st2.push(l2->val);
            l2 = l2->next;
        }

        ListNode *head = new ListNode(-1);
        int carry = 0;  // 进位

        while (!(st1.empty() && st2.empty())){
            int num1 = 0, num2 = 0;
            if(!st1.empty()){
                num1 = st1.top();
                st1.pop();
            }
            if(!st2.empty()){
                num2 = st2.top();
                st2.pop();
            }
            int sum = (num1 + num2 + carry) % 10;
            carry = num1 + num2 + carry >= 10;
            // 将求和后的位加入头部
            ListNode *pNode = new ListNode(sum);
            pNode->next = head->next;
            head->next = pNode;
        }

        // 如果还有进位
        if(carry){
            ListNode *pNode = new ListNode(1);
            pNode->next = head->next;
            head->next = pNode;
        }
        return head->next;
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
    vector<int> nums1 = {7,2,4,3};
    vector<int> nums2 = {5,6,4};
    ListNode *head1 = createList(nums1);
    ListNode *head2 = createList(nums2);
    Solution sol;
    ListNode *ret = sol.addTwoNumbers(head1,head2);
    while(ret!= nullptr){
        cout <<ret->val<<" ";
        ret = ret->next;
    }
    return 0;
}