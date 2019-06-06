#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 最长上升子序列：动态规划
 * 时间复杂度O(N^2) 空间复杂度O(N)
 */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        vector<int> dp(nums.size(),1);  // 表示以当前元素结尾的最长上升子序列长度；当前元素必须使用
        int maxLen = 0;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if(nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j]+1);    // 如果当前元素i大于j，则序列长度加一
            }
            maxLen = max(dp[i],maxLen);
        }

        return maxLen;
    }
};

/*
 * 最长上升子序列：动态规划+贪心+二分查找
 * 时间复杂度O(NlogN) 空间复杂度O(N)
 */
class SolutionII {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        vector<int> dp = {nums[0]}; // 第i个位置上的元素是长度为i+1的最长上升子序列的末尾元素最小值

        for (int i = 1; i < nums.size(); ++i) {
            int left = 0, right = dp.size();
            // 二分查找第一个大于等于num[i]的数的索引
            while (left<right){
                int mid = (left+right) /2;
                if(dp[mid] < nums[i])
                    left = mid +1;
                else
                    right = mid;
            }
            if (left == dp.size())
                dp.push_back(nums[i]);  // 比最末尾元素大，加入数组
            else
                dp[left] = nums[i];     // 替换
        }

        return dp.size();
    }
};

int main(){
    vector<int> nums = {10,9,2,5,3,7,101,18}; // 6
    SolutionII sol;
    cout << sol.lengthOfLIS(nums) << endl;
    return 0;
}

