#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 时间复杂度O(N)，空间复杂度O(N)
 */
class SolutionI {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0],nums[1]);

        vector<int> dp(nums.size(), 0); // 前i个的最大价值
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for (int i = 2; i < nums.size(); ++i) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }

        return dp.back();

    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0],nums[1]);

        int valNminus2 = nums[0], valNminus1 = max(nums[0],nums[1]);
        int maxVal = 0;
        for (int i = 2; i < nums.size(); ++i) {
            int tmp = valNminus1;
            maxVal = max(valNminus1, valNminus2 + nums[i]);
            valNminus2 = valNminus1;
            valNminus1 = maxVal;
        }
        return maxVal;
    }
};
int main(){
    vector<int> nums = {2,7,9,3,1};
    Solution sol;
    cout << sol.rob(nums) << endl;
    return 0;
}

