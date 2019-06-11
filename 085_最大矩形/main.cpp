#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 动态规划
 * 时间复杂度O(mn^2) 空间复杂度O(mn)
 * m,n为数组行列数
 */
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int> (cols, 0));
        int currentArea = 0, maxArea = 0;
        int currentWidth = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '0') continue;

                currentWidth = dp[i][j] = j>0? dp[i][j-1]+1:1; // 当前位置最大宽度

                // 往上遍历以该节点为右下角的柱状图最大面积
                for (int k = i; k >= 0 && dp[k][j] != 0; --k) {
                    currentWidth = min(currentWidth, dp[k][j]); // 更新当前矩形宽度
                    currentArea = currentWidth * (i-k + 1);     // 计算当前面积
                    maxArea = max(currentArea, maxArea);        // 更新最大面积
                }
            }
        }
        return maxArea;
    }
};

/*
 * 动态规划
 * 时间复杂度O(mn) 空间复杂度O(n)
 * m,n为数组行列数
 */
class SolutionII {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> left(cols, 0);      // 最左边的1位置 左边界
        vector<int> right(cols, cols);  // 右边界
        vector<int> height(cols, 0);
        int maxArea = 0;
        for (int i = 0; i < rows; ++i) {
            int curLeft = 0;            // 遇到的最右边的0的序号加1
            int curRight = cols;        // 遇到的最左边的0的序号
            for (int j = 0; j < cols; ++j) {
                if(matrix[i][j] == '1')
                    height[j] += 1;
                else
                    height[j] = 0;
            }
            // 更新left
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '1')
                    left[j] = max(left[j],curLeft);
                else{
                    left[j] = 0;
                    curLeft = j+ 1;
                }
            }
            // 更新right
            for (int j = cols-1; j >=0 ; --j) {
                if (matrix[i][j] == '1')
                    right[j] = min(right[j],curRight);
                else{
                    right[j] = cols;
                    curRight = j;
                }
            }
            // 更新最大面积
            for (int j = 0; j < cols; ++j) {
                maxArea = max(maxArea, height[j] * (right[j] - left[j]));
            }
        }
        return maxArea;
    }
};

int main(){
    vector<vector<char >> nums = {{'1' ,'0', '1', '0', '0'},
                                  {'1', '0', '1', '1', '1'},
                                  {'1', '1', '1', '1', '1'},
                                  {'1', '0', '0', '1', '0'}};
    SolutionII sol;
    cout << sol.maximalRectangle(nums) << endl;
    return 0;
}

