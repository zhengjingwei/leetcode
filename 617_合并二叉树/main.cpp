struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 * 直接在t1树上更新
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1 && !t2) return nullptr;
        if(!t2) return t1;
        if(!t1) return t2;
        t1->left = mergeTrees(t1->left,t2->left);
        t1->right =  mergeTrees(t1->right,t2->right);
        t1->val += t2->val;
        return t1;
    }
};