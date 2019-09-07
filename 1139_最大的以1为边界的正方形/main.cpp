#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 建立预处理加速
 * 时间复杂度O(n^3) 空间复杂度O(n^2)
 */
class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> right(m, vector<int>(n, 0));    // right[i][j]表示从(i,j)出发向右连续1的个数
        vector<vector<int>> down(m, vector<int>(n, 0));     // down[i][j]表示从(i,j)出发向下连续1的个数
        initMap(grid,right,down);
        // 边长从大到小判断O(min(m,n))
        for (int len = min(m,n); len >0 ; --len) {
            if(hasLenOfSquare(len, right, down))
                return len*len;
        }
        return 0;
    }

private:
    // 判断是否有边长为len的正方形存在 O(n^2)
    bool hasLenOfSquare(int len, vector<vector<int>>&right, vector<vector<int>>& down){
        // 选取(i,j)作为左上角，判断是否存在边都是1的正方形
        for (int i = 0; i <= right.size()-len; ++i) {
            for (int j = 0; j <= right[0].size() - len ; ++j) {
                if(right[i][j]>= len && down[i][j] >= len
                    && down[i][j+len-1] >= len && right[i+len-1][j]>= len)
                    return true;
            }
        }
        return false;
    }
    // 建立记录表
    void initMap(vector<vector<int>> &m, vector<vector<int>> &right, vector<vector<int>> &down){
        int r = m.size()-1, c = m[0].size()-1;
        // 右下角元素
        if(m[r][c] == 1){
            right[r][c] = 1;
            down[r][c] = 1;
        }
        // 最后一列
        for (int i = r-1; i >= 0; --i) {
            if(m[i][c] == 1){
                right[i][c] = 1;
                down[i][c] = down[i+1][c] +1;
            }
        }
        // 最后一行
        for (int j = c-1; j >=0 ; --j) {
            if(m[r][j] == 1){
                right[r][j] = right[r][j+1] +1;
                down[r][j] = 1;
            }
        }

        // 其余位置元素
        for (int i = r-1; i >= 0; --i) {
            for (int j = c-1; j >=0 ; --j) {
                if(m[i][j] == 1){
                    right[i][j] = right[i][j+1] +1;
                    down[i][j] = down[i+1][j] +1;
                }
            }
        }
    }
};

int main(){
    Solution sol;
    vector<vector<int>> m = {{1,1,1},{1,0,1},{1,1,1}};
    cout << sol.largest1BorderedSquare(m) << endl;
    return 0;
}