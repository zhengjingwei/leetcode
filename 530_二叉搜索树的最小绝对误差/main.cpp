class Solution {
    int ret = INT_MAX;
    TreeNode *last = nullptr; 
public:
    int getMinimumDifference(TreeNode* root) {
        if(!root) return 0;
        getMinimumDifference(root->left);
        if(last)
            ret = min(ret,root->val - last->val);
        last = root;
        getMinimumDifference(root->right);
        return ret;
    }
};