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
    TreeNode* last = nullptr;
    int minDiff = INT_MAX;
public:
    int minDiffInBST(TreeNode* root) {
        inOrder(root);
        return minDiff;
    }
    
    void inOrder(TreeNode* root){
        if(!root) return;
        inOrder(root->left);
        if(last)
            minDiff = min(minDiff, root->val - last->val);
        last = root;
        inOrder(root->right);
    }
};