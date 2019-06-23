#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 回溯
 */
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        if(candidates.empty()) return ret;
        vector<int> curr;
        combinationSumCore(candidates, target, 0, curr, ret);
        return ret;
    }

    void combinationSumCore(vector<int>& candidates, int target, int begin, vector<int>& curr, vector<vector<int>>& ret){
        if(target == 0){
            ret.push_back(curr);    // curr的和正好等于target
            return;
        }
        else if(target<0)           // curr和大于target
            return;
        for (int i = begin; i < candidates.size(); ++i) {   // 注意用变量begin控制curr数组内的数字都是从小到大
            curr.push_back(candidates[i]);
            combinationSumCore(candidates, target-candidates[i], i, curr, ret); // target-candidates[i]表示选择i元素
            curr.pop_back();
        }
    }
};

int main(){
    vector<int> nums = {2,3,5};
    int target = 8;
    Solution sol;
    vector<vector<int>> ret = sol.combinationSum(nums,target);
    for (auto rows:ret){
        for (auto v:rows)
            cout << v <<" ";
        cout << endl;
    }
    return 0;
}