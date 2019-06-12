/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal/
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ret;
        if(!root) return ret;
        s.push(root);
        while(!s.empty()){
            root = s.top();
            s.pop();
            ret.push_back(root->val);
            if(root->right)
                s.push(root->right);
            if(root->left)
                s.push(root->left);
        }
        return ret;
    }
};