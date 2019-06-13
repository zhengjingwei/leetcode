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
 * 非递归中序遍历
 * 用一个栈存储未访问的右子节点
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(!root) return ret;
        stack<TreeNode *> s;
        TreeNode *last = nullptr;
        while (root  || !s.empty()){
            while (root){
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            ret.push_back(root->val);
            root = root->right;
        }
        return ret;
    }
};

int main(){

    return 0;
}

