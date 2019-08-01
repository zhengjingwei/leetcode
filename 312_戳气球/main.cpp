#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// 1 暴力法
// 超时
class SolutionI {
public:
    int maxCoins(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        nums.insert(nums.begin(), 1);   // 开头和结尾补1
        nums.insert(nums.end(), 1);
        return helper(nums, 1, n);
    }

private:
    int helper(vector<int>& nums, int l, int r){
        if(l >= r)
            return nums[l-1] * nums[l] * nums[r+1];
        // 最后打爆nums[l]的方案与最后打爆nums[r]的方案先比
        int ret = max(nums[l-1] * nums[l] * nums[r+1] + helper(nums, l+1, r),
                      nums[l-1] * nums[r] * nums[r+1] + helper(nums, l, r-1));
        // 尝试中间位置气球被最后打爆的每一种方案
        for (int i = l+1; i <r ; ++i)
            ret = max(ret, nums[l-1] * nums[r+1] * nums[i] + helper(nums, l, i-1) + helper(nums, i+1, r));
        return ret;
    }
};

// 2 动态规划
// 时间复杂度O(n^3) 空间复杂度O(n^2)
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        int n = nums.size();
        nums.insert(nums.begin(), 1);   // 开头和结尾补1 避免判断越界
        nums.insert(nums.end(), 1);
        vector<vector<int>> dp(n+2, vector<int> (n+2, 0));
        for (int i = 1; i <=n ; ++i) {
            dp[i][i] = nums[i-1] * nums[i] *nums[i+1];  // 初始化区间大小为1的dp值
        }
        // 从下往上 从左往后迭代计算
        // dp[l][r]值值依赖同一行左边dp[][r-1]和同一列下边dp[l+1][]的有效位置
        for (int l = n; l >= 1 ; --l) {
            for (int r = l+1; r <= n ; ++r) { // 注意只有 r>= l才有效
                // 求解dp[l][r], 表示戳nums[l..r]所有气球的最大分数
                int finalL = nums[l-1] * nums[r+1] * nums[l] + dp[l+1][r];
                int finalR = nums[l-1] * nums[r+1] * nums[r] + dp[l][r-1];
                // 最后打爆nums[l]的方案与最后打爆nums[r]的方案先比
                dp[l][r] = max(finalL, finalR);
                for (int i = l+1; i < r; ++i) {
                    // 尝试中间位置气球被最后打爆的每一种方案
                    dp[l][r] = max(dp[l][r], nums[l-1] * nums[r+1] * nums[i] + dp[l][i-1] + dp[i+1][r]);
                }
            }
        }
        return dp[1][n];
    }
};

int main(){
    vector<int> nums = {3,1,5,8};
    Solution sol;
    cout << sol.maxCoins(nums) << endl;
    return 0;
}

