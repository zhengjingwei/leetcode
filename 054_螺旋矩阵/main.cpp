#include <iostream>
#include <bits/stdc++.h>
using namespace std;


/*
 * 螺旋矩阵（顺时针打印矩阵）
 * 分解成4步
 */

// 1
class Solution {
    vector<int> ret;
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return ret;
        int aR = 0, aC = 0;                             // 左上角坐标
        int bR = matrix.size()-1, bC = matrix[0].size()-1;  // 右下角坐标
        while (aR <= bR && aC <= bC){
            printCircle(matrix, aR++, aC++, bR--, bC--);
        }
        return ret;
    }
private:
    void printCircle(vector<vector<int>>& m, int aR, int aC, int bR, int bC){
        if(aR == bR){
            // 子矩阵只有一行
            for(int i = aC; i<= bC; ++i)
                ret.push_back(m[aR][i]);
        }else if (aC == bC){
            // 子矩阵只有一列
            for(int i = aR; i <= bR; ++i)
                ret.push_back(m[i][aC]);
        }else{
            // 一般情况
            int curR = aR, curC = aC;
            
            while(curC < bC)    // 从左到右打印
                ret.push_back(m[aR][curC++]);
            
            while(curR < bR)    // 从上到下打印
                ret.push_back(m[curR++][bC]);

            while(curC > aC)    // 从右往左打印
                ret.push_back(m[bR][curC--]);

            while(curR > aR)    // 从下往上打印
                ret.push_back(m[curR--][aC]);
        }
    }
};


// 2 
class SolutionII {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if(matrix.empty() || matrix[0].empty()) return ret;
        int rows = matrix.size(), cols = matrix[0].size();
        int round = min(rows, cols);
        // 观察规律可以看出终止条件是该圈打印的左上角坐标之和大于等于行数和列数的较小值
        for (int k = 0; 2*k < round; ++k) {
            printCircle(matrix,k,ret);
        }
        return ret;
    }

private:
    // (index,index)是该圈打印的起始坐标
    void printCircle(vector<vector<int>>& matrix, int index, vector<int> &ret){
        int rows = matrix.size(), cols =  matrix[0].size();

        int endX = rows - 1 - index;    // 终止横坐标
        int endY = cols - 1 - index;    // 终止纵坐标
        // 从左往右
        for (int j = index; j <= endY; ++j)
            ret.push_back(matrix[index][j]);

        // 从上到下
        // 需要第二步条件：终止行号大于起始行号；圈内至少两行
        if(index < endX){
            for (int i = index+1; i <= endX; ++i) {
                ret.push_back(matrix[i][endY]);
            }
        }

        // 从右到左
        // 需要第三步条件：终止行号大于起始行号；圈内至少两行两列
        // 需要第四步条件：圈内至少三行两列
        if(endX>index && endY > index){
            for (int j = endY-1; j >= index ; --j) {
                ret.push_back(matrix[endX][j]);
            }
        }

        // 从下到上
        // 需要第四步条件：圈内至少三行两列；
        if(endX -1 > index && endY > index){
            for (int i = endX -1; i >= index+1 ; --i) {
                ret.push_back(matrix[i][index]);
            }
        }
    }
};


int main(){
    Solution sol;
    vector<vector<int>> nums = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> ret = sol.spiralOrder(nums);
    for (auto v:ret)
        cout<<v<<" ";
    return 0;
}