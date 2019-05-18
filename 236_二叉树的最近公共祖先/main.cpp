#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 所有的递归的返回值有4种可能性，null、p、q、公共祖先
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)        // 遍历到空的叶节点返回null
            return root;
        if (root == p || root == q) // 当找到p或q时返回该节点
            return root;    // ；注意，如果公共祖先是自己(pq)，则并不需要找另一个；因为先序遍历找到一个会直接返回

        TreeNode *left = lowestCommonAncestor(root->left, p, q);    // 返回的结点进行保存，可能是null
        TreeNode *right = lowestCommonAncestor(root->right, p, q);  // 也可能是pq，还可能是公共祖先
        if (left!= nullptr && right!= nullptr)  // 如果左右孩子都存在，说明pq都出现；该根节点为公共祖先
            return root;
        else if(left!= nullptr) //否则我们返回已经找到的那个值（存储在left，与right中），p或者q或其祖先
            return left;
        else if(right!= nullptr)
            return right;

        return nullptr;
    }
};


int main(){

    return 0;
}

