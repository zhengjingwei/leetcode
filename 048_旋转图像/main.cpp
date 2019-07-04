#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 转置+镜像对称
 * 时间复杂度O(N^2)
 */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty() || matrix.size() == 1) return;
        int n = matrix.size();
        // 转置
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // 镜像对称
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n/2; ++j) {
                swap(matrix[i][j], matrix[i][n-1-j]);
            }
        }
    }
};

/*
 * 遍历每一圈
 * 四个边的元素顺时针转
 * 每个元素访问一遍，时间复杂度O(N^2)
 */
class SolutionI {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty() || matrix.size() == 1) return;
        int n = matrix.size();
        for (int i = 0; i < n/2; ++i) {
            int begin = i;
            int end = n - i -1;
            for (int j = 0; j < end - begin; ++j) {
                int tmp = matrix[begin][begin+j];   // 左上
                matrix[begin][begin+j] = matrix[end -j][begin]; // 左上=左下，上=左
                matrix[end-j][begin] = matrix[end][end-j];      // 左下=右下，左=下
                matrix[end][end-j] = matrix[begin+j][end];      // 右下=右上，下=右
                matrix[begin+j][end] = tmp;                     // 右上=左上，右=上
            }
        }
    }
};

int main(){
    Solution sol;
    vector<vector<int>> nums = {{1,2,3},{4,5,6},{7,8,9}};
    sol.rotate(nums);
    for (auto rows:nums){
        for(auto v:rows)
            cout << v << " ";
        cout << endl;
    }
    return 0;
}