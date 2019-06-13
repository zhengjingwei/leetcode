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
 * 非递归后序遍历
 * 用一个栈存储未访问的右子节点
 * 用一个变量last存储上一个访问的节点，用来判断右子节点是否访问过
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
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
            if(root->right == nullptr || root->right == last){  // 右子树已经遍历
                ret.push_back(root->val);
                s.pop();
                last = root;
                root = nullptr;
            }
            else
                root = root->right; // 右子树未遍历
        }
        return ret;
    }
};

/*
 * 非递归后序遍历
 * 将简洁的非递归先序遍历修改为 根->右->左 顺序遍历，然后将最后得到的递归序列翻转
 * 得到后序遍历 左->右->根
 */
class SolutionII {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(!root) return ret;
        stack<TreeNode *> s;
        s.push(root);
        while ( !s.empty()){
            root = s.top();
            s.pop();
            ret.push_back(root->val);
            if (root->left)
                s.push(root->left);
            if (root->right)
                s.push(root->right);
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};

int main(){

    return 0;
}

