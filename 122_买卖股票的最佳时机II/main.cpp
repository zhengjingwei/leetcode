#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
 * 动态规划一次遍历
 * 时间复杂度 O(n) 空间复杂度O(1)
 */
class SolutionI {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;

        int peak = prices[0];   // 峰 极大值
        int valley = prices[0]; // 谷 极小值
        int ret = 0;
        int i = 0;
        // 累加每一对紧邻着的波峰-波谷差值
        while (i < prices.size()-1){
            while (i+1 < prices.size() && prices[i] >= prices[i+1]) ++ i;   // 找波谷
            valley = prices[i];
            while (i+1 < prices.size() && prices[i] <= prices[i+1]) ++ i;   // 找波峰
            peak = prices[i];
            if (peak - valley > 0)
                ret += peak - valley;
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

        int ret = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if(prices[i] - prices[i-1] > 0)     // 通过连续累加的方式将峰谷之差累加
                ret += prices[i] - prices[i-1];
        }
        return ret;
    }
};


int main(){
    vector<int> nums = {7,1,5,3,6,4};
    Solution sol;
    cout << sol.maxProfit(nums) << endl; // 5
    return 0;
}

