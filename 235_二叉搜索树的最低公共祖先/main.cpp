struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;
        if(p->val > q->val) swap(p,q);  // 保证p为较小值q为较大值

        if(p->val < root->val && q->val > root->val || root == p || root == q)
            return root;    // 如果p，q分别在root的左右两边，说明root是最近公共祖先
        else if(p->val < root->val && q->val < root->val)   // 如果p,q都在root左边，则左节点更近
            return lowestCommonAncestor(root->left,p,q);
        else if(p->val > root->val && q->val > root->val)   // 如果p,q都在root右边，则右节点更近
            return lowestCommonAncestor(root->right,p,q);
        return nullptr;
    }
};