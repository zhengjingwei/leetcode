#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 * 设置变量控制翻转
 */
class SolutionI {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root) return ret;
        queue<TreeNode *> q;
        q.push(root);
        int currentLayerNodes = 1;  // 当前层待打印节点数
        int nextLayerNodes = 0;     // 下一层待打印节点数
        bool printLeft = true;      // 当前层打印方向
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
            if(!printLeft)
                reverse(currentLayer.begin(),currentLayer.end());
            ret.push_back(currentLayer);
            printLeft = !printLeft; // 翻转打印方向
            currentLayerNodes = nextLayerNodes;
        }
        return ret;
    }
};

/*
 * 两个栈，不翻转
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root) return ret;
        stack<TreeNode*> s1;    // 奇数层栈 从左往右
        stack<TreeNode*> s2;    // 偶数层栈 从右往左
        s2.push(root);
        while (!s1.empty() || !s2.empty()){
            vector<int> tmp;
            while (!s2.empty()){
                TreeNode* node = s2.top();
                tmp.push_back(node->val);
                s2.pop();
                if(node->left)
                    s1.push(node->left);
                if(node->right)
                    s1.push(node->right);
            }
            if(!tmp.empty()) ret.push_back(tmp);
            tmp.clear();
            while (!s1.empty()){
                TreeNode* node = s1.top();
                tmp.push_back(node->val);
                s1.pop();
                if(node->right)             // 注意需要先入栈右节点，再入栈左节点
                    s2.push(node->right);   // 这样下一轮才满足所有节点从左往右顺序，否则会交错
                if(node->left)
                    s2.push(node->left);
            }
            if(!tmp.empty()) ret.push_back(tmp);
        }
        return ret;
    }
};