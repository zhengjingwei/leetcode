/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    vector<int> ret;
public:
    vector<int> preorder(Node* root) {
        if(!root) return ret;
        preorderCore(root);
        return ret;
    }
    
    void preorderCore(Node* root){
        if(!root) return;
        ret.push_back(root->val);
        for(auto node: root->children)
            preorder(node);
    }
    
};