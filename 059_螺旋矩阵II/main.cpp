#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n,0));
        int round = n;
        int num = 1;    // 当前需要打印数字
        for (int i = 0; i*2 < n ; ++i) {
            printCircle(matrix, i, num);
        }
        return matrix;
    }

private:
    void printCircle(vector<vector<int>>& matrix, int index, int& num){
        int rows = matrix.size(), cols =  matrix[0].size();

        int endX = rows - 1 - index;    // 终止横坐标
        int endY = cols - 1 - index;    // 终止纵坐标
        // 从左往右
        for (int j = index; j <= endY; ++j)
            matrix[index][j] = num++;

        // 从上到下
        // 需要第二步条件：终止行号大于起始行号；圈内至少两行
        if(index < endX){
            for (int i = index+1; i <= endX; ++i) {
                matrix[i][endY] = num++;
            }
        }

        // 从右到左
        // 需要第三步条件：终止行号大于起始行号；圈内至少两行两列
        // 需要第四步条件：圈内至少三行两列
        if(endX>index && endY > index){
            for (int j = endY-1; j >= index ; --j) {
                matrix[endX][j] = num++;
            }
        }

        // 从下到上
        // 需要第四步条件：圈内至少三行两列；
        if(endX -1 > index && endY > index){
            for (int i = endX -1; i >= index+1 ; --i) {
                matrix[i][index] = num++;
            }
        }
    }
};




int main(){
    Solution sol;
    vector<vector<int>> nums = sol.generateMatrix(3);

    for (auto rows:nums){
        for (auto n:rows)
            cout<<n<<" ";
        cout << endl;
    }
    return 0;
}