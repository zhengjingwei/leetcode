#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 动态规划
 */
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        vector<long > dp(target+1,0);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if(i >= nums[j])
                    dp[i] += dp[i-nums[j]] %INT_MAX;
            }
        }
        return dp[target];
    }
};

int main(){
//    vector<int> nums = {4,2,1};
//    int target = 32;
    vector<int> nums = {1,2,3};
    int target = 4;
    Solution sol;
    cout<< sol.combinationSum4(nums, target)<<endl;
//    vector<vector<int>> ret = sol.combinationSum3(k,n);
//    for (auto rows:ret){
//        for (auto v:rows)
//            cout << v <<" ";
//        cout << endl;
//    }
    return 0;
}