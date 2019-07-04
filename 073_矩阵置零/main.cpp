#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * O(mn)空间复杂度
 */
class SolutionI {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return;
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<bool>> flag(rows, vector<bool>(cols,false));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if(matrix[i][j] == 0){
                    // 标记同一行非0元素
                    for (int k = 0; k < cols; ++k)
                        if(matrix[i][k]!=0)
                            flag[i][k] = true;
                    // 标记同一列非0元素
                    for (int k = 0; k < rows; ++k)
                        if(matrix[k][j]!=0)
                            flag[k][j] = true;
                }
            }
        }
        // 置零
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if(flag[i][j])
                    matrix[i][j] = 0;
            }
        }
    }
};

/*
 * 两个set存储需要置零的行号和列号
 * 空间复杂度O(m+n)
 */
class SolutionII {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return;
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<bool>> flag(rows, vector<bool>(cols,false));
        set<int> rowSet, colSet;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if(matrix[i][j] == 0){
                    rowSet.insert(i);
                    colSet.insert(j);
                }
            }
        }
        // 置零
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if(rowSet.count(i)!=0 || colSet.count(j)!=0)
                    matrix[i][j] = 0;
            }
        }
    }
};


/*
 * 利用数组的首行和首列来记录0值，相当于上一方法的set
 * 从数组下标的A[1][1]开始遍历，额外两个布尔变量标记首行首列是否需要置零
 * 时间复杂度O(mn)
 * 空间复杂度O(1)
 */
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return;
        int rows = matrix.size(), cols = matrix[0].size();
        bool rowFlag = false, colFlag = false;
        // 检查首行是否需要置零
        for (int j = 0; j < cols; ++j){
            if(matrix[0][j] == 0){
                rowFlag = true;
                break;
            }
        }
        // 检查首列是否需要置零
        for (int i = 0; i < rows; ++i) {
            if(matrix[i][0] == 0){
                colFlag = true;
                break;
            }
        }

        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // 将上面标记的行列置为0
        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        // 首行置零
        if(rowFlag){
            for (int j = 0; j < cols; ++j)
                matrix[0][j] = 0;
        }
        // 首列置零
        if(colFlag){
            for (int i = 0; i < rows; ++i)
                matrix[i][0] = 0;
        }
    }
};

int main(){
    Solution sol;
    vector<vector<int>> nums = {{1,1,1},{1,0,1},{1,1,1}};
    sol.setZeroes(nums);
    for (auto rows:nums){
        for(auto v:rows)
            cout << v << " ";
        cout << endl;
    }
    return 0;
}