#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 时间复杂度O(N^2) 空间复杂度O(N^2)
 */
class SolutionI {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;
        int rows = obstacleGrid.size(), cols = obstacleGrid[0].size();
        if (obstacleGrid.back().back() == 1 ||obstacleGrid[0][0] == 1)
            return 0;

        vector<vector<long >> dp(rows, vector<long >(cols, 0));
        dp[0][0] = 1;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                    continue;
                }
                if(i==0 && j==0) continue;
                long up = 0, left = 0;
                if(i-1>=0) up = dp[i-1][j];
                if(j-1>=0) left = dp[i][j-1];
                dp[i][j] = up+left;
            }
        }
        return dp.back().back();
    }
};

/*
 * 动态规划，使用obstacleGrid数组作为dp数组
 * 时间复杂度O(N^2) 空间复杂度O(1)
 */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;
        int rows = obstacleGrid.size(), cols = obstacleGrid[0].size();
        if (obstacleGrid.back().back() == 1 ||obstacleGrid[0][0] == 1)
            return 0;

        obstacleGrid[0][0] = 1;
        // 第一列元素
        for (int i = 1; i < rows; ++i)
            obstacleGrid[i][0] = (obstacleGrid[i][0] == 0 && obstacleGrid[i-1][0] == 1 ) ? 1:0; // 设置为1表示有1条路径
        // 第一行元素
        for (int j = 1; j < cols; ++j)
            obstacleGrid[0][j] = (obstacleGrid[0][j] == 0 && obstacleGrid[0][j-1] == 1)? 1:0;   // 设置为1表示有1条路径


        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                if(obstacleGrid[i][j] == 0)
                    obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
                else
                    obstacleGrid[i][j] = 0;
            }
        }
        return obstacleGrid.back().back();
    }
};

int main(){
    vector<vector<int>> nums = {{0,0,0},{0,1,0},{0,0,0}};
    Solution sol;
    cout << sol.uniquePathsWithObstacles(nums) << endl; // 3
    return 0;
}

