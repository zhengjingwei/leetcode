struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 * 验证二叉搜索树：中序遍历应该是顺序的
 */
class Solution {
    int *last = nullptr;    // 记录上一个访问节点，目的是第一个访问节点的判断
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        if(!isValidBST(root->left)) return false;   // 左子树判断
        if(last && *last >= root->val) return false;    // 注意第一个节点需要单独判断
        last = &(root->val);
        if(!isValidBST(root->right)) return false;  // 右子树判断
        return true;
    }
};