struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int maxLen = 0;
public:
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        longestCore(root);
        return maxLen;
    }

    // 从root出发节点值为root->val的最长连续路径长度
    int longestCore(TreeNode* root){
        if(!root) return 0;
        int left = longestCore(root->left);
        int right = longestCore(root->right);
        int leftLen = 0, rightLen = 0;  // 左右部分值为root->val的连续路径长度
        if(root->left && root->left->val == root->val)
            leftLen = left + 1;         //
        if(root->right && root->right->val == root->val)
            rightLen = right + 1;
        maxLen = max(maxLen, leftLen+ rightLen);
        return max(leftLen, rightLen);
    }
};