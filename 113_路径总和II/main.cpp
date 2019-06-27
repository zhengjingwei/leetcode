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
 * 先序遍历 回溯
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        if(!root) return ret;
        vector<int> curr;   // 当前路径
        hasPathSum(root, sum, curr, ret);
        return ret;
    }

private:
    void hasPathSum(TreeNode* root, int sum, vector<int>& curr, vector<vector<int>>& ret) {
        sum -= root->val;
        curr.push_back(root->val);
        if(sum == 0 && !root->left && !root->right) {
            ret.push_back(curr);    // 满足条件打印
            return ;
        }
        if(root->left){
            hasPathSum(root->left, sum,curr,ret);
            curr.pop_back();        // 回溯
        }
        if(root->right){
            hasPathSum(root->right,sum,curr,ret);
            curr.pop_back();        // 回溯
        }
    }
};