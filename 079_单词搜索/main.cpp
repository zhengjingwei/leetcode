#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || word.empty())
            return false;

        string path;
        bool isFind = false;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                isFind = findWordsCore(board, i, j, path, word);
                if(isFind) return isFind;
            }
        }
        return isFind;
    }

    bool findWordsCore(vector<vector<char>>& board, int row, int col, string &path, string word){
        bool isFind = false;
        if(row>=0 && row<board.size() && col>=0 && col<board[0].size() && board[row][col]!='#' ){
            char ch = board[row][col];
            path.push_back(ch);

            if(path.size() > word.size() || word.substr(0,path.size()) != path){
                path.pop_back();
                return false;
            }

            board[row][col] = '#';
            if(path == word) return true;

            isFind = findWordsCore(board, row-1, col, path, word)||
                                 findWordsCore(board, row+1, col, path, word)||
                                 findWordsCore(board, row, col-1, path, word)||
                                 findWordsCore(board, row, col+1, path, word);

            // 恢复
            board[row][col] = ch;
            path.pop_back();
        }
        return isFind;
    }
};