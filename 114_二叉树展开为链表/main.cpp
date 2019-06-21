#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
 * 非递归先序遍历
 * 题目要求是单向链表，left指针需要全部置为null
 */
class SolutionI {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()){
            TreeNode *node = s.top();
            s.pop();
            if(node->right) s.push(node->right);
            if(node->left) s.push(node->left);
            node->left = nullptr;
            node->right = s.empty()? nullptr: s.top();
        }
    }
};

/*
 * 递归，后序遍历
 */
class Solution {
private:
    TreeNode *pre = nullptr;    // 全局变量存储上一个节点
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        flatten(root->right);
        flatten(root->left);
        root->right = pre;
        root->left = nullptr;
        pre = root;
    }
};



int main(){
    Solution sol;
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(5);
    TreeNode *node6 = new TreeNode(6);
    node1->left = node2, node1->right = node5;
    node2->left = node3, node2->right = node4;
    node5->right = node6;

    sol.flatten(node1);
    TreeNode *node = node1;
    while(node){
        cout<<node->val<<" ";
        node = node->right;
    }
    return 0;
}