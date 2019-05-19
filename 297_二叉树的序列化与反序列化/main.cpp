#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr)
            return "#,";
        string ret = to_string(root->val);
        ret.push_back(',');
        ret+=serialize(root->left);
        ret+=serialize(root->right);
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data){
        return deserializeCore(data);
    }

    TreeNode* deserializeCore(string &data) {
        if(data[0]=='#') {
            if(data.size() > 2)
                data = data.substr(2);
            return nullptr;
        } else{
            TreeNode *root = new TreeNode(helper(data));
            root->left = deserializeCore(data);
            root->right = deserializeCore(data);
            return root;
        }
    }

private:
    // 用于提取序列化中的数字
    int helper(string &data){
        int pos = data.find(',');
        int val = stoi(data.substr(0,pos));
        data = data.substr(pos+1);
        return val;
    }
};

int main(){
    TreeNode *root = new TreeNode(1);
    TreeNode *node1 = new TreeNode(2);
    TreeNode *node2 = new TreeNode(3);
    TreeNode *node3 = new TreeNode(4);
    TreeNode *node4 = new TreeNode(5);
    root->left = node1,root->right = node2;
    node2->left = node3,node2->right = node4;

    Codec c;
    string s = c.serialize(root);
    cout<<s<<endl;

    return 0;
}

