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
 * 层序遍历+递归
 * 层序遍历确定开始的节点，从该节点递归往下找符合的路径
 * 思路：首先先序递归遍历每个节点，再以每个节点作为起始点递归寻找满足条件的路径。
 * 时间复杂度O(n^2)
 */
class SolutionI {
    int ret = 0;
public:
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            TreeNode *node = q.front();
            q.pop();
            hasPathSum(node,sum);   // 以该节点为起点往下找
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        return ret;
    }

private:
    // 返回：从root开始和为sum的路径数
    void hasPathSum(TreeNode* root, int sum) {
        if(!root) return;
        sum -= root->val;
        if(sum == 0)
            ++ret;
        hasPathSum(root->left,sum);
        hasPathSum(root->right,sum);
    }
};

/*
 * 双重递归
 * 时间复杂度：O(n^2)
 */
class Solution {
    int ret = 0;
public:
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        hasPathSum(root,sum);
        pathSum(root->left,sum);
        pathSum(root->right,sum);
        return ret;
    }

private:
    // 返回：从root开始和为sum的路径数
    void hasPathSum(TreeNode* root, int sum) {
        if(!root) return;
        sum -= root->val;
        if(sum == 0)
            ++ret;
        hasPathSum(root->left,sum);
        hasPathSum(root->right,sum);
    }
};


/*
 * hashmap+一遍递归
 * 类似于数组的前n项和的思路，比如sum[4] == sum[1]，那么1到4之间的和肯定为0
 * 时间复杂度：O(n)
 */
class SolutionII {
    unordered_map<int,int> m;   // <当前路径和, 数量>
    int ret = 0;
public:
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        m[0] = 1;   // 某个节点值就为sum的情况
        hasPathSum(root,sum,0);
        return ret;
    }

private:
    void hasPathSum(TreeNode* root, int sum, int currSum) {
        if(!root) return;
        currSum += root->val;
        ret += m[currSum - sum];    // 如果存在m[currSum - sum]，说明中间有一段和为sun
        m[currSum] +=  1;           // 从根节点到当前节点的路径总和
        hasPathSum(root->left, sum,currSum);
        hasPathSum(root->right, sum,currSum);
        m[currSum] -= 1;            // 回溯，去掉该节点的路径和
    }
};