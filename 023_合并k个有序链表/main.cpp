#include <iostream>
#include <bits/stdc++.h>
using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
 * 逐一两两合并链表
 * 时间复杂度O(kn) 空间复杂度O(1)
 */
class SolutionI {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = nullptr;
        if(lists.empty()) return head;
        for (auto list:lists) {
            head = mergeTwoLists(head, list);
        }
        return head;
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        if(l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

/*
 * 分治；k个链表配对并将同归对中的链表合并-两两合并，不需要对大部分节点重复遍历多次。
 * 时间复杂度O(nlogk) 空间复杂度O(1)
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = nullptr;
        if(lists.empty()) return head;
        int len = lists.size();
        int interval = 1;   // 当前合并后的原链表数
        while (interval <= len){
            for (int i = 0; i < len - interval; i+=interval*2)
                lists[i] = mergeTwoLists(lists[i], lists[i+interval]);
            interval *= 2;
        }
        return head;
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        if(l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};




int main(){
    return 0;
}