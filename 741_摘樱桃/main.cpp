#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 动态规划
 * 时间复杂度O(n^3) 空间复杂度O(n^2)
 */

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int N = grid.size(), M = (N<< 1) -1;    // M表示从(0,0)到(N-1,N-1)的格子数
        vector<vector<int>> dp(N, vector<int> (N,0));
        dp[0][0] = grid[0][0];

        for (int n = 1; n < M; ++n) {
            for (int i = N-1; i >= 0; --i) {
                for (int p = N-1; p >=0 ; --p) {
                    int j = n - i, q = n-p;
                    // 出界判断，出现障碍
                    if (j < 0 || j >= N || q < 0 || q >= N || grid[i][j] < 0 || grid[p][q] < 0) {
                        dp[i][p] = -1;
                        continue;
                    }

                    if(i>0) dp[i][p] = max(dp[i][p], dp[i-1][p]);
                    if (p > 0) dp[i][p] = max(dp[i][p], dp[i][p - 1]);
                    if (i > 0 && p > 0) dp[i][p] = max(dp[i][p], dp[i - 1][p - 1]);

                    if (dp[i][p] >= 0) dp[i][p] += grid[i][j] + (i != p ? grid[p][q] : 0);
                }
            }
        }

        return max(dp[N-1][N-1],0);
    }
};

int main(){
    vector<vector<int>> grid = {{0,1,-1},
                        {1,0,-1},
                        {1,1,1}};
    Solution sol;
    cout<<sol.cherryPickup(grid)<<endl;    // 0
    return 0;
}