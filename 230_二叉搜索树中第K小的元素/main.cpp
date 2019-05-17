#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ret;
        midOrder(root,k,ret);
        return ret;
    }

    bool midOrder(TreeNode* root, int &k, int &ret){
        if(root == nullptr)
            return false;

        bool left = midOrder(root->left);
        if(left) return true;

        if(k==1){
            ret = root->val;
            return true;
        }
        else k--;

        bool right = midOrder(root->right);
        if(right) return true;

        return false;
    }
};


int main(){

    return 0;
}

