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
 * 层序遍历记录节点数
 */
class SolutionI {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        int ret = 0;
        q.push(root);
        while (!q.empty()){
            TreeNode *node = q.front();
            ++ret;
            q.pop();
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        return ret;
    }
};

/*
 * 递归
 */
class SolutionII {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int leftNodes = countNodes(root->left);
        int rightNodes = countNodes(root->right);
        return leftNodes + rightNodes + 1;
    }
};

/*
 * 递归+完全二叉树性质
 * O(log N)
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int h = height(root);
        if(h == height(root->right) + 1) // 右子树高度=根高度-1，左子树一定是完全二叉树
            return (1<< (h-1)) + countNodes(root->right);
        else // 右子树高度=根高度-2
            return (1 << (h-2)) + countNodes(root->left);;
    }

private:
    // 完全二叉树高度
    int height(TreeNode *root){
        int count = 0;
        while (root){
            root = root->left;
            count ++;
        }
        return count;
    }
};