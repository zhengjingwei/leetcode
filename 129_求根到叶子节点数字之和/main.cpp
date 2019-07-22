/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int ret = 0;
    int cur = 0;
public:
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        cur = cur * 10 + root->val; // 加上当前节点值
        sumNumbers(root->left);
        sumNumbers(root->right);
        if(!root->left && !root->right) 
            ret += cur;
        cur /= 10;              // 回溯过程去掉当前节点值
        return ret;
    }
};