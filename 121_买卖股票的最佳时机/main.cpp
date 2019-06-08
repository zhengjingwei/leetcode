#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 暴力法，循环
 * 时间复杂度 O(n^2) 空间复杂度O(1)
 */
class SolutionI {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;

        int ret = 0;
        for (int i = 1; i < prices.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (prices[i] > prices[j])
                    ret = max(prices[i] - prices[j], ret);
            }
        }
        return ret;
    }
};

/*
 * 动态规划一次遍历
 * 时间复杂度 O(n) 空间复杂度O(1)
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;

        int maxDiff = 0;        // 当前最大利润
        int minPrice = INT_MAX; // 当前最小的峰值
        for (int i = 0; i < prices.size(); ++i) {
            if (prices[i] < minPrice)
                minPrice = prices[i];
            else if (prices[i] - minPrice > maxDiff)
                maxDiff = prices[i] - minPrice;
        }
        return maxDiff;
    }
};


int main(){
    vector<int> nums = {7,1,5,3,6,4};
    Solution sol;
    cout << sol.maxProfit(nums) << endl; // 5
    return 0;
}

