#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node(int x): val(x), left(NULL),right(NULL),next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

/*
 * 递归
 */
class Solution {
public:
    Node* connect(Node* root) {
        if(!root || (!root->left &&!root->right)) return root;
        con(root);
        return root;
    }

    void con(Node* root){
        if(!root) return;
        if(root->left && root->right)                       // 左右孩子连接
            root->left->next = root->right;
        Node *p = root->right ? root->right: root->left;    // 左右孩子中最右的节点
        Node *pSib = root->next;                            // 右侧兄弟节点
        while(p && pSib){
            if(pSib->left){
                p->next = pSib->left;
                break;
            } else if(pSib->right){
                p->next = pSib->right;
                break;
            } else
                pSib=pSib->next;
        }

        con(root->right);
        con(root->left);
    }
};

/* 先确保 root.right 下的节点的已完全连接，因 root.left 下的节点的连接
 需要 root.left.next 下的节点的信息，若 root.right 下的节点未完全连
 接（即先对 root.left 递归），则 root.left.next 下的信息链不完整，将
 返回错误的信息。可能出现的错误情况如下图所示。此时，底层最左边节点将无
 法获得正确的 next 信息：
                  o root
                 / \
             root.left  o —— o  root.right
               /    / \
                      o —— o   o
             /        / \
                    o        o   o*/

/*
 * 层序遍历
 */
class SolutionI {
public:
    Node* connect(Node* root) {
        if(!root || (!root->left &&!root->right)) return root;
        queue<Node*> q;
        q.push(root);
        int currLayerNodes = 1;
        int nextLayerNodes = 0;
        while(!q.empty()){
            Node *last = nullptr;
            while (currLayerNodes-- > 0){
                Node *node = q.front();
                q.pop();
                if(last!= nullptr)
                    last->next = node;
                last = node;
                if(node->left!= nullptr) {
                    q.push(node->left);
                    nextLayerNodes++;
                }
                if(node->right!= nullptr) {
                    q.push(node->right);
                    nextLayerNodes++;
                }
            }
            currLayerNodes = nextLayerNodes;
            nextLayerNodes = 0;
        }
        return root;
    }
};


int main(){
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);
    Node *node7 = new Node(7);
    node1->left = node2, node1->right = node3;
    node2->left = node4, node2->right = node5;
    node3->right= node7;
    Solution sol;
    sol.connect(node1);
    return 0;
}