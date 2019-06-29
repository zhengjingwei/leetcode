#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * DFS
 */
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows,vector<bool>(cols, false));
        int ret = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if(!visited[i][j] && grid[i][j] == '1'){
                    ret ++;
                    dfs(grid,visited,i,j);
                }
            }
        }
        return ret;
    }

private:
    // 深度优先搜索将与该位置相连的‘1’节点全部标记为访问过
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col){
        if(row < 0 || col < 0 || row >= grid.size() || col>=grid[0].size() || visited[row][col]) return;
        if(grid[row][col] == '1') {
            visited[row][col] = true;
            dfs(grid,visited,row-1,col);
            dfs(grid,visited,row+1,col);
            dfs(grid,visited,row,col-1);
            dfs(grid,visited,row,col+1);
        }
    }
};



class SolutionI {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows,vector<bool>(cols, false));
        int ret = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if(grid[i][j] == '1'){
                    ret ++;
                    dfs(grid,i,j);
                }
            }
        }
        return ret;
    }

private:
    // 深度优先搜索将与该位置相连的‘1’节点全部标记为访问过
    void dfs(vector<vector<char>>& grid,  int row, int col){
        if(row < 0 || col < 0 || row >= grid.size() || col>=grid[0].size() || grid[row][col] == '2') return;
        if(grid[row][col] == '1') {
            grid[row][col] = '2';
            dfs(grid,row-1,col);
            dfs(grid,row+1,col);
            dfs(grid,row,col-1);
            dfs(grid,row,col+1);
        }
    }
};

int main(){
    Solution sol;
    vector<vector<char>> grid = {{'1','1','1','1','0'},
                                 {'1','1','0','1','0'},
                                 {'1','1','0','0','0'},
                                 {'0','0','0','0','0'}};
    cout << sol.numIslands(grid) << endl;
    return 0;
}