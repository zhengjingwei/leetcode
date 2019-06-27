struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 * 二叉搜索树中的众数：中序遍历统计
 */
class Solution {
    int *last = nullptr;// 上一个访问节点
    int cnt = 1;        // 当前遍历数的计数
    int maxCnt = 1;     // 当前众数的计数
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> ret;
        if(!root) return ret;
        inOrder(root, ret);
        return ret;
    }

    void inOrder(TreeNode* root, vector<int>& ret){
        if(!root) return;
        inOrder(root->left, ret);   // 左子树

        if(last)                // 当前数字和上一个相同
            cnt = (root->val == *last)? cnt+1:1;

        if(cnt == maxCnt )      // 当前数为众数
            ret.push_back(root->val);
        else if (cnt > maxCnt){
            ret.clear();
            ret.push_back(root->val);
            maxCnt = cnt;
        }
        last = &(root->val);
        inOrder(root->right, ret);  // 右子树
    }
};