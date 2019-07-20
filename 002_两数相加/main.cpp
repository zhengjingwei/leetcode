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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 || (!l1->next && !l1->val)) return l2;
        if(!l2 || (!l2->next && !l2->val)) return l1;

        ListNode *dummy = new ListNode(-1);
        ListNode *head = dummy;
        int carry = 0;
        while (l1 || l2){
            int num1 = 0, num2 = 0;
            if (l1) {
                num1 = l1->val;
                l1 = l1->next;
            }
            if (l2) {
                num2 = l2->val;
                l2 = l2->next;
            }
            ListNode *node = new ListNode((num1 + num2 + carry) % 10);
            carry = (num1 + num2 + carry) >= 10;
            head->next = node;
            head = node;
        }

        if(carry){
            ListNode *node = new ListNode(carry);
            head->next = node;
        }

        return dummy->next;
    }
};