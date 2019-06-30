#include <iostream>
#include <bits/stdc++.h>
using namespace std;


/*
 * 动态规划
 * O(n^2) 超时
 */
class SolutionI {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),INT_MAX);  // 到达该位置需要的最小跳跃数
        int end = nums.size() -1;
        dp[0] = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 1; i + j <= min(end, i+nums[i]); ++j)
                    dp[i + j] = min(dp[i + j], dp[i] + 1);
        }
        return dp.back();
    }
};

/*
 * 贪心：每次在可跳范围内选择可以使得跳的更远的位置。
 */
class Solution {
public:
    int jump(vector<int>& nums) {
        int end = 0;        // 目前跳的结束点
        int maxPos = 0;     // 下一跳的最远距离
        int ret = 0;        // 最少跳跃数
        for (int i = 0; i < nums.size()-1; ++i) {
            maxPos = max(maxPos, nums[i] + i);  // 计算下一跳的最远距离
            if(i == end){
                end = maxPos;
                ++ ret;
            }
        }
        return ret;
    }
};

int main(){
    vector<int> nums = {2,3,1,1,4,2,1};
    Solution sol;
    cout << sol.jump(nums) << endl;
    return 0;
}

