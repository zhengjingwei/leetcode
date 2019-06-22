struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 * 递归
 * 时间复杂度O(n) 空间复杂度O(n)
 */
class SolutionI {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()||inorder.empty()||preorder.size() != preorder.size()) return nullptr;

        int rootVal = preorder.front(), leftLen = 0;
        while(inorder[leftLen]!= rootVal) ++ leftLen;
        int rightLen = preorder.size() - leftLen -1;
        TreeNode *root = new TreeNode(rootVal);
        vector<int> preorderLeft(preorder.begin()+1, preorder.begin()+1+leftLen);
        vector<int> preorderRight(preorder.end() - rightLen, preorder.end());
        vector<int> inorderLeft(inorder.begin(), inorder.begin() + leftLen);
        vector<int> inorderRight(inorder.end() - rightLen, inorder.end());
        root->left = buildTree(preorderLeft, inorderLeft);
        root->right = buildTree(preorderRight, inorderRight);
        return root;
    }
};

/*
 * 递归
 * 时间复杂度O(n) 空间复杂度O(1)
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()||inorder.empty()||preorder.size() != preorder.size()) return nullptr;
        return buildTreeCore(0, inorder.size()-1, 0, inorder.size()-1, preorder, inorder);
    }

    TreeNode* buildTreeCore(int preLeft, int preRight, int inLeft, int inRight, vector<int>& preorder, vector<int>& inorder){
        if(preLeft>preRight || inLeft>inRight) return nullptr;
        TreeNode* root = new TreeNode(preorder[preLeft]);   // 根节点
        int inRoot = inLeft;                                // 中序遍历中根节点的位置
        while (inRoot <= inRight && inorder[inRoot] != preorder[preLeft]) ++ inRoot;
        int leftLen = inRoot - inLeft;                      // 左子树的长度，也是根节点在中序中的位置
        root->left = buildTreeCore(preLeft+1, preLeft + leftLen, inLeft, inRoot-1, preorder,inorder);
        root->right = buildTreeCore(preLeft+leftLen+1, preRight, inRoot+1, inRight, preorder,inorder);
        return root;
    }
};