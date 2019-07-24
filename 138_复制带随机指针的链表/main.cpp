#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

/*
 * 在原链表节点后复制新节点
 * （1）复制链表节点
 * （2）设置随机指针
 * （3）分割链表
 * 时间复杂度：O(n) 空间复杂度：O(1)
 */
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;

        Node *pNode = head;
        Node *pNext = nullptr;

        // 复制链表节点
        while(pNode){
            pNext = pNode->next;
            pNode->next =  new Node(pNode->val, nullptr, nullptr);
            pNode->next->next = pNext;
            pNode = pNext;
        }

        // 设置随机指针
        pNode = head;
        Node *pCopy = nullptr;
        while (pNode){
            pCopy = pNode->next;
            pCopy->random = pNode->random->next;
            pNode = pNode->next->next;
        }

        // 分割链表 调整next指针
        pNode = head;
        Node *copyHead = head->next;
        while (pNode){
            pNext = pNode->next->next;
            pCopy = pNode->next;
            pNode->next = pNext;    // 原链表
            pCopy->next = pNext != nullptr ? pNext->next : nullptr; // 复制链表
            pNode = pNext;
        }

        return copyHead;
    }
};


/*
 * 哈希表存储原链表节点到复制链表节点的映射
 * 时间复杂度：O(n) 空间复杂度：O(n)
 */
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;

        Node *pNode = head;
        unordered_map<Node*,Node*> m;
        // 复制链表节点并建立映射
        while(pNode){
            Node *copyNode = new Node(pNode->val, nullptr, nullptr);
            m[pNode] = copyNode;
            pNode = pNode->next;
        }

        // 设置指针
        pNode = head;
        while (pNode){
            m[pNode]->next = m[pNode->next];
            m[pNode]->random = m[pNode->random];
            pNode = pNode->next;
        }

        return m[head];
    }
};

int main(){
    return 0;
}