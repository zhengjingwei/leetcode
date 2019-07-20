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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool isSame1 = (!q && !p) || (p && q && p->val == q->val);
        if(!q && !p)
            return true;
        else if((p && !q) || (q&&!p))   // 其中一个为空
            return false;
        else if(p->val == q->val){
            return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        }
        else
            return false;
    }
};