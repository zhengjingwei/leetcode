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
    int maxSum = 0;
public:
    int rob(TreeNode* root) {
        if(!root) return 0;
        int prevSum = 0;
        robCore(root, prevSum);
        return maxSum;
    }

private:
    // 返回值：包含该节点为的最大收益；
    // 引用返回prevSum：不包含末尾节点的最大收益
    int robCore(TreeNode* root, int& prevSum){
        if(!root){
            prevSum = 0;
            return 0;
        }
        if(!root->left && !root->right) {           // 无左右子树
            prevSum = 0;
            maxSum = max(maxSum, root->val);
            return root->val;
        }
        int prevLeft = 0, prevRight = 0;            // 左右子树不包含左右子节点部分的最大收益
        int left = robCore(root->left, prevLeft);   // 左子树包含左子节点部分的最大收益
        int right = robCore(root->right, prevRight);

        int sumWithRoot = root->val+ prevLeft+prevRight;        // 包含根节点值的最大收益
        prevSum = max(left,prevLeft) + max(right,prevRight);    // 不包含根节点的最大收益
        maxSum = max(maxSum, max(sumWithRoot,prevSum));         // 更新最大收益
        return sumWithRoot;
    }
};



int main(){
    TreeNode *node1 = new TreeNode(3);
    TreeNode *node2 = new TreeNode(4);
    TreeNode *node3 = new TreeNode(5);
    TreeNode *node4 = new TreeNode(1);
    TreeNode *node5 = new TreeNode(3);
    TreeNode *node6 = new TreeNode(1);
    node1->left = node2, node1->right = node3;
    node2->left = node4, node2->right = node5;
    node3->right = node6;
    Solution sol;
    cout << sol.rob(node1) <<endl;
    return 0;
}