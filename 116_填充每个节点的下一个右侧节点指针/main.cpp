struct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;
}


class Solution {
public:
    Node* connect(Node* root) {
        if(!root || (!root->left &&!root->right)) return root;
        inOrder(root);
        return root;
    }

    void inOrder(Node *root){
        if(!root || !root->left) return;
        root->left->next = root->right;

        if(root->next)
            root->right->next = root->next->left;
        inOrder(root->left);
        inOrder(root->right);
    }
};