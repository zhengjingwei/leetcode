#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 回溯算法
 * 类似0-1背包，每个位置元素有选和不选两种选择，组合数共2^n种
 * 时间复杂度O(2^N) 空间复杂度O(N)
 */
class SolutionII {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        if(nums.empty()) return ret;
        vector<bool > take(nums.size(), false); // 辅助数组用来标记该位置元素是否选该位置元素
        subsetsCore(nums,0,take,ret);
        return ret;
    }
    void subsetsCore(vector<int> &nums, int begin, vector<bool> &take, vector<vector<int>> &ret){
        // 当位置到达末尾递归结束
        if (begin >= nums.size()){
            vector<int> tmp;
            for (int i = 0; i < nums.size(); ++i) {
                if(take[i])                     // 取take数组中值为true位置对应的元素
                    tmp.push_back(nums[i]);
            }
            ret.push_back(tmp);
            return;
        }
        take[begin] = true;
        subsetsCore(nums,begin+1, take, ret);   // 递归到下一元素
        take[begin] = false;
        subsetsCore(nums,begin+1, take, ret);
    }
};

/*
 * 迭代
 * 时间复杂度O(2^N) 空间复杂度O(n)
 */
class SolutionI {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        if(nums.empty()) return ret;
        ret.push_back(vector<int> {});
        for (auto num:nums){
            int len = ret.size();       // 当前遍历长度
            for (int i = 0; i < len; ++i) {
                vector<int> tmp = ret[i];   // 已有的组合，不选该元素
                tmp.push_back(num);         // 添加该元素
                ret.push_back(tmp);
            }
        }
        return ret;
    }
};

/*
 * 回溯算法优化
 * 集合的每个元素，都有可以选或不选，用二进制和位运算，可以很好的表示。
 * 时间复杂度O(N^2) 空间复杂度O(1)
 */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        if(nums.empty()) return ret;
        for (int i = 0; i <  1<<nums.size() ; ++i) {
            vector<int> tmp;
            for (int j = 0; j < int(log2(i))+1; ++j) {
                if((i >> j) & 1 == 1)
                    tmp.push_back(nums[j]);     // 根据i二进制中1的位置取得子集
            }
            ret.push_back(tmp);
        }

        return ret;
    }
};


int main(){
    SolutionII sol;
    vector<int> nums = {1,2,3};
    vector<vector<int>> ret = sol.subsets(nums);
    for (auto r:ret){
        for (auto v:r)
            cout<<v<<" ";
        cout<<endl;
    }
    return 0;
}