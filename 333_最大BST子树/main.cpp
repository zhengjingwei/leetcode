/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class ReturnType{
public:
    TreeNode *maxBSTRoot;   // 最大BST子树根节点
    int maxBSTSize;         // 最大BST子树节点数
    int min;                // 树节点最小值
    int max;                // 树节点最大值
    ReturnType(TreeNode* maxBSTRoot, int maxBSTSize, int min, int max ){
        this->maxBSTRoot = maxBSTRoot;
        this->maxBSTSize = maxBSTSize;
        this->min = min;
        this->max = max;
    }
};
class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        return helper(root).maxBSTSize;
    }

private:
    // 处理函数
    ReturnType helper(TreeNode *root){
        // 空树
        if(!root)
            return ReturnType(nullptr,0,INT_MAX,INT_MIN);

        ReturnType lData = helper(root->left);  // 左树信息
        ReturnType rData = helper(root->right); // 右树信息
        // 信息整合 root为根节点的子树的最小值
        int minVal = min(root->val, min(lData.min, rData.min));
        int maxVal = max(root->val, max(lData.max, rData.max));

        // 情况1，2：最大BST存在与其左子树或者右子树其中一个
        //          更新参数
        TreeNode *maxBSTRoot = lData.maxBSTSize >= rData.maxBSTSize ? lData.maxBSTRoot : rData.maxBSTRoot;
        int maxBSTSize = max(lData.maxBSTSize, rData.maxBSTSize);

        // 情况3：root左子树是以左孩子为根节点的最大BST，root右子树是以右孩子为根节点的最大BST
        //       并且root左子树最大值 < root值 < 右子树最小值
        if(lData.maxBSTRoot == root->left && rData.maxBSTRoot == root->right
            && lData.max < root->val && rData.min > root->val){
            maxBSTSize = lData.maxBSTSize + rData.maxBSTSize + 1;
            maxBSTRoot = root;
        }

        return ReturnType(maxBSTRoot,maxBSTSize, minVal, maxVal);
    }
};