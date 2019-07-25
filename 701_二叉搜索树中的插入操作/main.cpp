////递归
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)
            return new TreeNode(val);
        if(root->val < val)
            root->right = insertIntoBST(root->right,val);
        else
            root->left = insertIntoBST(root->left, val);
        return root;
    }
};

// 迭代
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)
            return new TreeNode(val);
        TreeNode *parent = root;
        TreeNode *p = root;
        while(p){
            parent = p;
            p = val < p->val ? p->left : p->right;
        }
        if(val < parent->val)
            parent->left = new TreeNode(val);
        else
            parent->right = new TreeNode(val);
        
        return root;
    }
};