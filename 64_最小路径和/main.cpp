#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 最小路径和
 * 动态规划
 * 时间复杂度O(mn) 空间复杂度O(n)
 */
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int rows = grid.size(), cols = grid[0].size();
        vector<int> dp(cols,0);
        dp[0] = grid[0][0];
        for (int i = 0; i<rows; ++i){
            for(int j = 0; j< cols; ++j){
                if (i==0&&j==0) continue;
                int up = INT_MAX, left = INT_MAX;
                if (j>0) left = dp[j-1];
                if (i>0) up = dp[j];
                dp[j] = min(left,up) + grid[i][j];
            }
        }
        return dp.back();
    }
};

int main(){
    vector<vector<int>> nums = {{1,3,1},{1,5,1},{4,2,1}};   // 7
    Solution sol;
    cout << sol.minPathSum(nums) << endl; // 3
    return 0;
}

