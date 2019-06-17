#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        if(nums.empty()) return ret;
        permuteCore(nums,0,ret);
        return ret;
    }

    // 回溯求解
    void permuteCore(vector<int>& nums, int begin, vector<vector<int>>& ret){
        if(begin >= nums.size()){               // 到达最后一元素 打印该排列
            vector<int> res;
            for (auto num:nums) {
                res.push_back(num);
            }
            ret.push_back(res);
            return;
        }

        for (int i = begin; i < nums.size(); ++i) {
            swap(nums[begin],nums[i]);          // 交换首元素和i位置元素
            permuteCore(nums, begin+1, ret);    // 递归到下一个元素
            swap(nums[begin],nums[i]);          // 恢复交换前位置
        }
    }
};



int main(){
    Solution sol;
    vector<int> nums = {1,2,3};
    vector<vector<int>> ret = sol.permute(nums);

    return 0;
}