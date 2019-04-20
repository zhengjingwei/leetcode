#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Trie {
private:
    Trie* next[26] = {};
    bool isEnd= false;      // 表明是否是单词结尾
public:
    /** Initialize your data structure here. */
    Trie() {}

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for(char ch:word){
            ch -= 'a';      // 得到字符的序号
            if(!node->next[ch]){
                // 若当前字符不存在 创建新节点
                node->next[ch] = new Trie();
            }
            node = node->next[ch];
        }
        node->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for(char ch: word){
            ch-= 'a';
            if(!node->next[ch]) // 如果不匹配
                return false;
            node = node->next[ch];
        }
        return node->isEnd;     // 只有当遍历到词的结尾时才成功
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        for (char ch:prefix){
            ch -= 'a';
            if(!node->next[ch])
                return false;
            node = node->next[ch];
        }
        return true;            // 前缀遍历结束则成功
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */


int main(){
    Trie *t = new Trie();
    t->insert("apple");
    cout<<t->search("apple")<<endl;
    cout<<t->startsWith("app")<<endl;
    cout<<t->search("app")<<endl;
    return 0;
}

