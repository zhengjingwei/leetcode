struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 * 中序遍历变种
 * 把二叉搜索树转换为累加树：右->根->左 访问顺序，从大到小累加
 */
class Solution {
    int sum = 0;
public:
    TreeNode* convertBST(TreeNode* root) {
        inOrder(root);
        return root;
    }

    void inOrder(TreeNode* root){
        if(!root) return;
        inOrder(root->right);
        root->val += sum;
        sum = root->val;
        inOrder(root->left);
    }
};