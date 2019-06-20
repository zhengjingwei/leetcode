struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isSymmetricCore(root,root);
    }
    
    bool isSymmetricCore(TreeNode* node1, TreeNode* node2) {
        if(node1 == nullptr && node2 == nullptr)
            return true;    // 同时为空指针
        else if(node1 == nullptr || node2 == nullptr)
            return false;   // 一个空，一个非空
        if(node1->val != node2->val)
            return false;   // 值不同
        
        return isSymmetricCore(node1->left, node2->right) && isSymmetricCore(node1->right, node2->left);
    }
};

class SolutionI {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        while (!q.empty()){
            TreeNode* node1 = q.front(); q.pop();
            TreeNode* node2 = q.front(); q.pop();
            if(node1 == nullptr && node2 == nullptr) continue;
            if(node1 == nullptr || node2 == nullptr) return false;
            if(node1->val != node2->val) return false;
            q.push(node1->left);
            q.push(node2->right);
            q.push(node1->right);
            q.push(node2->left);
        }
        return true;
    }
};