#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
 * 动态规划
 * 从右下到左上计算
 * 时间复杂度O（mn）空间复杂度O（n）
 */
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n,INT_MAX));
        dp[m-1][n-1] = max(1, 1 - dungeon.back().back());
        for (int i = m-1; i >= 0; --i) {
            for (int j = n-1; j >= 0 ; --j) {
                if(i == m-1 && j == n-1)
                    continue;
                int right = INT_MAX, down = INT_MAX;
                if(i+1 < m)
                    down = max(dp[i+1][j] - dungeon[i][j], 1);
                if(j+1 < n)
                    right = max(dp[i][j+1]- dungeon[i][j], 1);
                dp[i][j] = min(down, right);
            }
        }
        return dp[0][0];
    }
};

/*
 * 空间压缩优化
 * 空间复杂度：O（n）
 */
class SolutionI {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<int> dp(n, 0);
        dp[n-1] = max(1, 1 - dungeon.back().back());
        for (int i = m-1; i >= 0; --i) {
            for (int j = n-1; j >= 0 ; --j) {
                if(i == m-1 && j == n-1)
                    continue;
                int right = INT_MAX, down = INT_MAX;
                if(i+1 < m)
                    down = max(dp[j] - dungeon[i][j], 1);
                if(j+1 < n)
                    right = max(dp[j+1]- dungeon[i][j], 1);
                dp[j] = min(down, right);
            }
        }
        return dp[0];
    }
};

int main(){
    vector<vector<int>> nums = {{-2,-3,3},{-5,-10,1},{10,30,-5}};
    SolutionI sol;
    cout << sol.calculateMinimumHP(nums) << endl;
}

