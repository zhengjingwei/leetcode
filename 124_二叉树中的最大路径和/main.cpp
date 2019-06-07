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
    int maxPathSum(TreeNode* root) {
        if(root == nullptr) return 0;
        int ret = INT_MIN;
        maxSum(root,ret);
        return ret;
    }

    /*
     * 递归求解：ret是保存全局最大路径和
     * 返回值local表示以该节点为末尾节点（从下往上）的序列的最大路径和
     * 以当前节点为根节点，分为以下四种情况
     * 1.只有当前节点
     * 2.当前节点+左子树
     * 3.当前节点+右子树
     * 4.当前节点+左右子树
     * 这四种情况的最大值即为当前节点为根的最大路径和
     * 此最大值要和已经保存的最大值比较，得到整个树的最大路径值
     */
    int maxSum(TreeNode*root, int &ret){
        if (root == nullptr) return 0;
        int leftVal = maxSum(root->left, ret);
        int rightVal = maxSum(root->right, ret);

        // 前三种情况的最大值能用来继续递归
        int local = max(max(root->val + leftVal,root->val+rightVal),root->val);

        // 第四种情况当前节点+左右子树不能参与递归，只能用来更新全局最大值
        ret = max(max(root->val + leftVal + rightVal,local), ret);
        return local;
    }
};

int main(){
    TreeNode *node1 = new TreeNode(-10);
    TreeNode *node2 = new TreeNode(9);
    TreeNode *node3 = new TreeNode(20);
    TreeNode *node4 = new TreeNode(15);
    TreeNode *node5 = new TreeNode(7);
    node1->left = node2, node1->right = node3;
    node3->left = node4, node3->right = node5;
    Solution sol;
    cout << sol.maxPathSum(node1) << endl;
    return 0;
}

