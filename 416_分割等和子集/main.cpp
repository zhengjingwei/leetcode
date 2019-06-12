#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 动态规划
 * 时间复杂度O(n) 空间复杂度O(ns)
 * s为和的一半
 */
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.size()<=1) return false;
        int sum = accumulate(nums.begin(),nums.end(),0);
        if (sum & 0x01) return false;   // 如果数组和为奇数，肯定无法分割
        sum = sum >> 1;
        vector<vector<bool>> dp(nums.size(), vector<bool>(sum+1, false));
        for (int i = 0; i < nums.size(); ++i) {
            if(nums[i] == sum) return true; // 只选该数字
            dp[i][nums[i]] = true;          // 只选该数字
            if(i==0) continue;
            for (int j = 1; j < sum+1; ++j) {
                bool choose = false;
                bool notChoose = dp[i-1][j];        // 不选该数字
                if (j-nums[i]>0)
                    choose = dp[i-1][j-nums[i]];    // 选该数字
                else if(j == nums[i])
                    choose = true;

                dp[i][j] = dp[i][j] || choose || notChoose;
            }
            if(dp[i][sum]) return true; // 如果找到，直接返回
        }
        return dp.back().back();
    }
};


int main(){
    vector<int> nums = {1,5,11,5};
    vector<int> nums2 = {1,2,3,5};
    vector<int> nums3 = {3,3,3,4,5};
    vector<int> nums4 = {1,2,5};
    Solution sol;
    cout<<sol.canPartition(nums)<<endl;     // 1
    cout<<sol.canPartition(nums2)<<endl;    // 0
    cout<<sol.canPartition(nums3)<<endl;    // 1
    cout<<sol.canPartition(nums4)<<endl;    // 0
    return 0;
}

