#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
 * 动态规划
 * 利用matrix[i'][j'] > matrix[i][j]且dp[i'][j']已经计算过的元素
 */
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols,0));  // 矩阵记忆位置 (x, y) 的最大递增序列长度

        int maxLen = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                maxLen = max(maxLen, dfs(matrix, i, j, dp));
            }
        }
        return maxLen;
    }

    int dfs(vector<vector<int>> &matrix, int x, int y, vector<vector<int>> &dp){
        if (dp[x][y]) return dp[x][y];

        vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}}; // 上下左右四个方向
        dp[x][y] = 1;       // 该坐标访问，长度至少为1
        for (auto dir : dirs){
            int dx = dir[0], dy = dir[1];
            if ( x + dx<0 || x + dx>= matrix.size() || y+dy <0 || y + dy >= matrix[0].size())
                continue;   // 坐标出界
            if (matrix[x][y] <= matrix[x+dx][y+dy])
                continue;
            dp[x][y] = max(dp[x][y], dfs(matrix,x+dx,y+dy,dp) + 1);  // 回溯
        }
        return dp[x][y];
    }
};

int main(){
//    vector<vector<int>> nums = {{3,4,5},{3,2,6},{2,2,1}};
    vector<vector<int>> nums = {{9,9,4},{6,6,8},{2,1,1}};
    Solution sol;
    cout << sol.longestIncreasingPath(nums) << endl;
//    int dx = -1, dy = 0;
//    for (int i = 0; i < 4; ++i) {
//        tie(dx, dy) = make_pair(dy, -dx);
//        cout << dx<<" " << dy<< endl;
//    }
    return 0;
}

