#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
 * 链表递归
 */
class SolutionII {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return nullptr;
        return helper(head);
    }

private:
    TreeNode* helper(ListNode *head){
        if(!head) return nullptr;

        ListNode *fast = head, *slow = head;        // 设置快慢指针
        ListNode *prev = nullptr;                   // 记录slow的前一个节点
        while (fast!= nullptr && fast->next != nullptr){
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        if(prev!= nullptr)
            prev->next = nullptr;                   // 断开链表
        TreeNode *root = new TreeNode(slow->val);   // slow指向中间节点
        if(head!=slow)
            root->left = sortedListToBST(head);     // 递归构建左子树
        root->right = sortedListToBST(slow->next);  // 递归构建右子树
        return root;
    }
};

/*
 * 转成数组+递归
 */
class SolutionI {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return nullptr;
        vector<int> nums;
        while (head){
            nums.push_back(head->val);
            head = head->next;
        }
        return helper(nums,0,nums.size()-1);
    }

private:
    TreeNode* helper(vector<int>& nums, int left, int right){
        if(left > right)
            return nullptr;
        int mid = (left+ right) /2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = helper(nums, left,mid -1);
        root->right = helper(nums,mid+1, right);
        return root;
    }
};

/*
 * 中序遍历模拟
 */
class Solution {
    ListNode *headNode;
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return nullptr;
        int begin = 0, end = 0;
        ListNode *node = head;
        headNode = head;
        while(node->next != nullptr){
            ++end;
            node = node->next;
        }
        return helper(begin, end);
    }

private:
    TreeNode* helper(int begin,int end){
        if(begin > end)
            return nullptr;
        int mid = (begin + end) /2;
        TreeNode *left = helper(begin, mid-1);
        // 当链表左半边遍历完 headNode指向中间节点
        TreeNode *root = new TreeNode(headNode->val);
        root->left = left;
        headNode = headNode->next;  // 每次走一步，链表的顺序遍历正好对应了树的中序遍历
        root->right = helper(mid+1, end);
        return root;
    }
};