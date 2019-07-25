/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if(!root) 
            return true;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *l = nullptr, *r = nullptr;
        bool leaf = false;  // 要求之后都是叶子结点
        while(!q.empty()){
            root = q.front();
            q.pop();
            l = root->left, r = root->right;
            
            // 如果没有左孩子有孩子，不是完全二叉树
            if(!l && r) 
                return false;
            // 如果要求为叶子节点（无孩子节点），但是有孩子节点的
            if(leaf && (l ||r))
                return false;
            if(l) 
                q.push(l);
            if(r) 
                q.push(r);
            else
                leaf = true;
        }
        
        return true;
    }
};