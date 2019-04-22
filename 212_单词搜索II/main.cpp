#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Trie {
public:
    Trie* next[26] = {};
    bool isEnd= false;      // 表明是否是单词结尾

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

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.empty() || words.empty())
            return vector<string> {};

        Trie *obj = new Trie();
        for (string w:words)
            obj->insert(w);

        vector<string> ret;
        unordered_set<string> result_set;
        vector<vector<bool>> visited(board.size(), vector<bool> (board[0].size(), false));
        string path;    // 当前序列

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                findWordsCore(board, i, j, path, obj, result_set);
            }
        }

        for (auto it:result_set)
            ret.push_back(it);

        return ret;
    }

    void findWordsCore(vector<vector<char>>& board, int row, int col, string &path, Trie *obj, unordered_set<string> &ret){
        if(row>=0 && row<board.size() && col>=0 && col<board[0].size() && board[row][col]!='#' ){
            char ch = board[row][col];
            char chIndex = ch - 'a';
            // 如果当前单词不存在于所有单词的前缀中，则可以立即停止回溯
            if(obj->next[chIndex]){
                path.push_back(ch);
                obj = obj->next[chIndex];   // 需要前进到子节点
                board[row][col] = '#';

                if(obj->isEnd)
                    ret.insert(path);

                findWordsCore(board, row-1, col, path, obj, ret);
                findWordsCore(board, row+1, col, path, obj, ret);
                findWordsCore(board, row, col-1, path, obj, ret);
                findWordsCore(board, row, col+1, path, obj, ret);

                // 恢复
                board[row][col] = ch;
                path.pop_back();
            }
        }
    }
};


int main(){
    /* oath, eat */
//    vector<string> words = {"oath","pea","eat","rain"};
//    vector<vector<char>> board = {{'o','a','a','n'},
//                                  {'e','t','a','e'},
//                                  {'i','h','k','r'},
//                                  {'i','f','l','v'}};

//    vector<string> words = {"a"};
//    vector<vector<char>> board = {{'a','a'}};


    vector<string> words = {"aba","baa","bab","aaab","aaa","aaaa","aaba"};
    vector<vector<char>> board = {{'a','b'},{'a','a'}};  /* ["aaa","aaab","aaba","aba","baa"] */

    Solution sol;
    vector<string> ret = sol.findWords(board,words);
    for (auto s: ret)
        cout<<s<< endl;
    return 0;
}

