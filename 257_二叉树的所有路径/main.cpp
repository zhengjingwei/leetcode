class Solution {
    vector<string> ret;
    vector<int> cur;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root);
        return ret;
    }

    void dfs(TreeNode* root){
        if(!root) return;
        cur.push_back(root->val);
        if(!root->left && !root->right){
            string s;
            for(auto n: cur){
                s += to_string(n) + "->";
            }
            s.pop_back();
            s.pop_back();
            ret.push_back(s);
        }
        dfs(root->left);
        dfs(root->right);
        cur.pop_back();
    }
};