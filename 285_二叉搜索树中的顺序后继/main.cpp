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
    TreeNode *pPrev = nullptr;
    TreeNode *pNext = nullptr;
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(!root || !p) return nullptr;
        inorder(root,p);
        return pNext;
    }
    
    void inorder(TreeNode* root, TreeNode *p){
        if(!root) return;
        inorder(root->left,p);
        if(pPrev && pPrev == p)
            pNext = root;
        pPrev = root;
        inorder(root->right, p);
    }
};