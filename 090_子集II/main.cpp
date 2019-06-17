#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret = {{}};
        if(nums.empty()) return ret;
        sort(nums.begin(), nums.end());     // 排序
        int start = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int len = ret.size();
            if (i>0 && nums[i]!=nums[i-1])
                start = 0;          // 新数字，全部遍历
            for(int j = start; j < len; ++j){
                vector<int> tmp = ret[j];
                tmp.push_back(nums[i]);
                ret.push_back(tmp);
            }
            start = ret.size() - (len - start); // 重复数字,从上一轮新添加的部分开始
        }

        return ret;
    }
};


int main(){
    Solution sol;
    vector<int> nums = {5,5,5,5,5};
    vector<vector<int >> ret = sol.subsetsWithDup(nums);
    for (auto r:ret){
        for (auto v:r)
            cout<< v<<" ";
        cout<<endl;
    }

    return 0;
}