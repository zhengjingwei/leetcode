/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/
// 方法1：沿着parent向上找到头结点，再中序遍历得到后继
// 时间复杂度：O（n） 空间复杂度：O（n）
class Solution {
    Node *pPrev = nullptr;
    Node *pNext = nullptr;
public:
    Node* inorderSuccessor(Node* node) {
        if(!node) return nullptr;
        Node* root = node;
        while(root->parent)
            root = root->parent;
        inorder(root, node);
        return pNext;
    }
    
    void inorder(Node* root, Node* node){
        if(!root) return;
        inorder(root->left, node);
        if(pPrev && pPrev == node)
            pNext = root;
        pPrev = root;
        inorder(root->right, node);
    }
};


// 方法2：时间复杂度O(L) 空间复杂度O(1)
// 其中L为node和后继节点的实际距离
class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if(!node) return nullptr;
        
        // 如果node有右子树，则后继节点是右子树最左节点
        if(node->right){
            node = node->right;
            while(node->left)
                node = node->left;
            return node;
        }else{
            // 如果node没有右子树
            // 1：如果node是父节点的左孩子，则后继节点是父节点
            // 2: 如果node是父节点右孩子，则不断向上找到某个节点p，是其父节点的左孩子，则该父节点为后继
            Node* parent = node->parent;
            while(parent && parent->left!=node){
                node = parent;
                parent = node->parent;
            }
            return parent;
        }
    }
};