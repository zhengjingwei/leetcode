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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root) return ret;
        queue<TreeNode *> q;
        q.push(root);
        int currentLayerNodes = 1;  // 当前层待打印节点数
        int nextLayerNodes = 0;     // 下一层待打印节点数
        while (!q.empty()){
            int cnt = 0;            // 当前层已打印节点数
            nextLayerNodes = 0;
            vector<int> currentLayer;
            while(cnt < currentLayerNodes){
                TreeNode *node = q.front();
                q.pop();
                currentLayer.push_back(node->val);
                cnt ++;
                if(node->left) {
                    q.push(node->left);
                    nextLayerNodes++;
                }
                if(node->right) {
                    q.push(node->right);
                    nextLayerNodes++;
                }
            }
            ret.push_back(currentLayer);
            currentLayerNodes = nextLayerNodes;
        }
        return ret;
    }
};