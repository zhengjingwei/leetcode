#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 动态规划
 * 时间复杂度O(mn) 空间复杂度O(mn)
 * m为数组长度；n为数组的和
 */

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        auto sum = accumulate(nums.begin(), nums.end(), 0); // 和表示范围 [-sum, sum]
        if(nums.empty() ||  S > 1000 || abs(S) > sum)       // 超出表示范围
            return 0;

        vector<vector<int>> dp(nums.size(),vector<int>(sum+1,0));
        //dp[i][j]表示为到下标i为止和为j的方法数,由于负数等于正数取反，如果j是负数，其方法与j是相反数时相同，即dp[i][-j];
        dp[0][nums[0]] = (nums[0] == 0) ? 2 : 1;    // 取第一个数的方法数；nums[0]==0时正负号都可加

        for(int i = 1 ; i < nums.size();++i){
            for(int j = 0 ; j <= sum; ++j){
                int count1 = abs(j-nums[i]) > sum ? 0 : dp[i-1][abs(j-nums[i])];   // +号
                int count2 = ( j + nums[i] ) > sum ? 0 : dp[i-1][j+nums[i]];       // -号
                dp[i][j] = count1 + count2;
            }
        }
        return dp[nums.size()-1][abs(S)];
    }
};

/*
 * 动态规划
 * 时间复杂度O(mn) 空间复杂度O(n)
 * m为数组长度；n为数组的和
 */

class SolutionI {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if (nums.empty()) return 0;
        auto sum = accumulate(nums.begin(),nums.end(),0);   // 可以获得的和从-sum到sum
        if (S>sum || S <-sum) return 0; // 目标数超出可能的取值范围

        vector<int> dp(2 * sum + 1, 0);   // dp表示目标数范围[-sum,sum] -> [0, 2*sum]
        dp[sum] = 1;    // S=0时组合数为1
        for (auto num : nums){
            vector<int> dp_next(2* sum + 1, 0);
            for (int i = 0; i < dp.size(); ++i) {
                if (dp[i]){
                    dp_next[i+num] += dp[i];    // +号
                    dp_next[i-num] += dp[i];    // -号
                }
            }
            dp = dp_next;
        }
        return dp[S+sum];
    }
};

/*
 * DFS
 */
class SolutionII {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        return DFS(nums,0,0,S);
    }
    int  DFS(vector<int>& nums,int n,int sum,int S){
        if(n == nums.size())
            return (sum == S)?1:0;
        return DFS(nums,n+1,sum + nums[n],S) + DFS(nums,n+1,sum - nums[n],S);
    }
};

int main(){
    vector<int> nums = {1,1,1,1,1};
    Solution sol;
    cout << sol.findTargetSumWays(nums,3) << endl;
    return 0;
}

