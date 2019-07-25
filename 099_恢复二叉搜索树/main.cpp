class Solution {
public:
    void recoverTree(TreeNode* root) {
        if(!root) return;
        stack<TreeNode*> st;
        TreeNode *pPrev = nullptr;
        TreeNode *err1 = nullptr, *err2 = nullptr;
        // 非递归中序遍历
        while(!st.empty() || root){
            while(root){
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            if(pPrev && pPrev->val > root->val){
                err1 = err1 ? err1: pPrev;
                err2 = root;
            }
            pPrev = root;
            root = root->right;
        }
        
        swap(err1->val, err2->val);
    }
};