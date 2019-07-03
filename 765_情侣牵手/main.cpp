#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 贪心
 * 先记录下所有情侣和座位对应编号，
 * 然后开始迭代，找到与当前匹配的情侣进行交换，记录交换次数即可。
 * 时间复杂度O(N) 空间复杂度O(N)
 */
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        unordered_map<int,int> index;
        int ret = 0;

        for (int i = 0; i < row.size(); ++i)
            index[row[i]] = i;  // 记录位置

        for (int i = 0; i < row.size(); i+=2) {
            int next = row[i] ^ 1;      // 对应的情侣编号
            if(row[i+1] == next)
                continue;
            swap(row[index[next]], row[i+1]);   // 交换数组
            swap(index[row[index[next]]], index[row[i+1]]); // 交换坐标
            ++ ret;
        }
        return ret;
    }
};

/*
 * 直接查找
 * 时间复杂度O(N^2) 空间复杂度O(1)
 */
class SolutionI {
public:
    int minSwapsCouples(vector<int>& row) {
        int ret = 0;

        for (int i = 0; i < row.size(); i+=2) {
            int next = row[i] ^ 1;      // 对应的情侣编号
            if(row[i+1] == next) continue;
            for (int j = i+2; j < row.size(); ++j) {
                if(row[j] == next){
                    ++ret;
                    swap(row[j], row[i+1]);
                    break;
                }
            }
        }
        return ret;
    }
};


int main(){
    vector<int> nums = {0,2,4,6,7,1,3,5};
    Solution sol;
    cout << sol.minSwapsCouples(nums) << endl;
    return 0;
}

