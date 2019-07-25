// 层次遍历
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ret;
        if(!root) return ret;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int cnt = q.size();
            int maxVal = INT_MIN;
            while(cnt--){
                root = q.front();
                q.pop();
                maxVal = max(maxVal, root->val);
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
            }
            ret.push_back(maxVal);
        }
        
        return ret;
    }
};