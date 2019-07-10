#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * -1表示当前为1，下一次更新为0的细胞
 * 2表示当前为0，下一次更新为1的细胞
 */
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.empty() || board[0].empty()) return;
        int rows = board.size(), cols = board[0].size();

        // 标记状态
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int cnt = 0;
                // 统计活细胞数量
                for (int k = i-1; k <= i+1 ; ++k) {
                    for (int l = j-1; l <= j + 1 ; ++l) {
                        if(k<0 || l < 0|| k>=rows || l>=cols || (k==i && l ==j))
                            continue;
                        if(board[k][l] == 1 ||board[k][l] == -1)
                            cnt ++;
                    }
                }
                if (board[i][j] == 1){
                    if(cnt < 2 || cnt > 3)
                        board[i][j] =  -1;
                }
                else if(cnt == 3)
                    board[i][j] = 2;
            }
        }

        // 更新状态
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if(board[i][j] == -1)
                    board[i][j] = 0;
                else if(board[i][j] ==2)
                    board[i][j] = 1;
            }
        }
    }
};

int main(){
    Solution sol;
    vector<vector<int>> nums = {{0,1,0},
                                {0,0,1},
                                {1,1,1},
                                {0,0,0}};

    return 0;
}