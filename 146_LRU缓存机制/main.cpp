#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 用一个哈希表存储的key和双头列表节点地址
 * 用双头链表list存储对应哈希表的迭代器以及value值。双头链表便于对头尾节点插入删除操作
 */
class LRUCache {
public:
    LRUCache(int capacity) : _cap(capacity) {}

    // O(1)
    // hash 查找，如果找到了，就把 list 中的节点摘下来移到头部
    int get(int key) {
        auto it = _m.find(key);
        if(it == _m.end()) return -1;       // key不存在
        int val = it->second->second;
        _list.push_front(make_pair(key, val));  // 头部插入该节点
        _list.pop_back();
        _m[key] = _list.begin();
        return val;


    }
    // O(1)
    // 先查找旧 key 是否存在，如果存在，将节点移动到首部。
    // 如果不存在，插入新节点。
    // 如果容量超限，删除最脏的节点。
    void put(int key, int value) {
        auto it = _m.find(key);
        if (it!= _m.end())              // 旧key存在 删除链表节点
            _list.erase(it->second);

        _list.push_front(make_pair(key, value));   // 头部插入新节点
        _m[key] = _list.begin();        // map更新对应list头部位置迭代器

        if(_m.size() > _cap){            // 容量超限
            int dirtyKey = _list.back().first;
            _list.pop_back();
            _m.erase(dirtyKey);
        }
    }
private:
    unordered_map<int, list<pair<int,int >>::iterator> _m; // (key, value在list中节点的地址)
    list<pair<int,int>> _list;  // 每个节点存储key，以及value
    int _cap;
};


int main(){
    LRUCache cache =  LRUCache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    cache.get(1);       // 返回  1
    cache.put(3, 3);    // 该操作会使得密钥 2 作废
    cache.get(2);       // 返回 -1 (未找到)
    cache.put(4, 4);    // 该操作会使得密钥 1 作废
    cache.get(1);       // 返回 -1 (未找到)
    cache.get(3);       // 返回  3
    cache.get(4);       // 返回  4
    list<int> l;

    return 0;
}