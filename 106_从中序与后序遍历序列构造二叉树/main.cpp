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
 * 递归
 * 时间复杂度O(n) 空间复杂度O(1)
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty()||postorder.empty()||inorder.size() != postorder.size()) return nullptr;
        return buildTreeCore(0, inorder.size()-1, 0, inorder.size()-1, postorder, inorder);
    }

    TreeNode* buildTreeCore(int posLeft, int posRight, int inLeft, int inRight, vector<int>& posorder, vector<int>& inorder){
        if(posLeft>posRight || inLeft>inRight) return nullptr;
        TreeNode* root = new TreeNode(posorder[posRight]);  // 后序遍历最后节点为根节点
        int inRoot = inLeft;                                // 中序遍历中根节点的位置
        while (inRoot <= inRight && inorder[inRoot] != posorder[posRight]) ++ inRoot;
        int leftLen = inRoot - inLeft;                      // 左子树的长度，也是根节点在中序中的位置
        root->left = buildTreeCore(posLeft, posLeft + leftLen-1, inLeft, inRoot-1, posorder,inorder);
        root->right = buildTreeCore(posLeft+leftLen, posRight-1, inRoot+1, inRight, posorder,inorder);
        return root;
    }
};
