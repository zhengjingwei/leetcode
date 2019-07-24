/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
 * 递归构造左右子树
 */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.empty()) 
            return nullptr;
        return buildTree(preorder,0,preorder.size() -1);
    }

    TreeNode *buildTree(vector<int> &preorder, int begin, int end){
        if(begin > end || begin < 0 || end >= preorder.size())
            return nullptr;
        TreeNode *root = new TreeNode(preorder[begin]);
        int ll = begin + 1, lh = begin+1;
        while (lh <= end && preorder[lh] < root->val) ++lh;
        int rl = lh, rh = end;
        lh -- ;
        root->left = buildTree(preorder,ll,lh);
        root->right = buildTree(preorder,rl,rh);
        return root;
    }
};