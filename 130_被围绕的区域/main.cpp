#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 先找到没有被X围绕的O，标记为#；对边界的O进行DFS
 * 遍历矩阵将所有O改为X
 * 将所有#改为O
 */
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty()) return;
        int rows = board.size(), cols = board[0].size();
        // 将未被X围绕的O置为#
        for (int i = 0; i < rows; ++i) {
            dfs(board,i,0);
            dfs(board,i,cols-1);
        }
        for (int j = 0; j < cols; ++j) {
            dfs(board,0,j);
            dfs(board,rows-1,j);
        }
        // 被X围绕的O改为X
        for(int i = 1;i<rows-1;++i){
            for(int j = 1; j<cols-1; ++j){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        // 将边界上的O恢复
        for(int i = 0;i<rows;++i){
            for(int j = 0; j<cols; ++j){
                if(board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }

    void dfs(vector<vector<char>>& board, int i, int j){
        if(i<0 || j<0 || i>= board.size() || j>=board[0].size() || board[i][j] !='O')
            return;

        board[i][j] = '#';
        dfs(board,i-1,j);
        dfs(board,i+1,j);
        dfs(board,i,j-1);
        dfs(board,i,j+1);
    }
};


int main(){
    vector<vector<char>> nums = {{'X' ,'X' ,'X' ,'X'},
                         {'X' ,'O' ,'O' ,'X'},
                         {'X' ,'X' ,'O' ,'X'},
                         {'X' ,'O' ,'X' ,'X'}};
    Solution sol;
    sol.solve(nums);
    return 0;
}

