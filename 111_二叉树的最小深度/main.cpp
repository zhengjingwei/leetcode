#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 层序遍历 非递归
class Solution {
    int ret = 0;
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int nextLayerNodes = 1;
        int currLayerNodes = 1;
        while(!q.empty()){
            currLayerNodes = nextLayerNodes;
            nextLayerNodes = 0; // 下一层置零
            ret ++; // 深度计数+1
            while(currLayerNodes-- > 0){
                TreeNode *node = q.front();
                q.pop();
                if(node->left){
                    nextLayerNodes ++;
                    q.push(node->left);
                }
                if(node->right){
                    nextLayerNodes ++;
                    q.push(node->right);
                }
                if(!node->left && !node->right && ret>1)    // 注意要加上判断ret>1 根节点不能作为叶子节点
                    return ret;
            }
        }
        return ret;
    }
};

// 递归
// 对于树[1,2] 最小深度是2 因为根节点不能作为叶子节点
class SolutionI {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;

        int ret = INT_MAX;
        if(root->left)  // 根节点不能作为叶子节点，需要进行判断
            ret = min(ret, minDepth(root->left));
        if(root->right)
            ret = min(ret, minDepth(root->right));
        return ret + 1;
    }
};



int main(){
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(5);
    node1->left = node2, node1->right = node3;
    node2->left = node4, node2->right = node5;
    Solution sol;
    cout << sol.minDepth(node1) <<endl;
    return 0;
}