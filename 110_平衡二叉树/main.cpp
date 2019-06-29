class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int lHeight = getHeight(root->left);
        int rHeight = getHeight(root->right);
        return abs(lHeight - rHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right) ;
    }

    int getHeight(TreeNode *root){
        if(!root) return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
};