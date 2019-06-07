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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        int ret = INT_MIN;
        maxDiameter(root, ret);
        return ret;
    }

    int maxDiameter(TreeNode* root, int &ret){
        if (root == nullptr) return 0;
        int leftVal = maxDiameter(root->left, ret);
        int rightVal = maxDiameter(root->right, ret);

        int local = max(leftVal, rightVal) + 1;
        ret = max(ret, leftVal + rightVal);
        return local;
    }
};

int main(){
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(5);
    node1->left = node2, node1->right = node3;
    node2->left = node4, node2->right = node5;
    Solution sol;
    cout << sol.diameterOfBinaryTree(node1) << endl;
    return 0;
}

