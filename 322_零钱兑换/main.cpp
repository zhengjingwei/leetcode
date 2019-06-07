#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 动态规划
 * 时间复杂度O(nk) 空间复杂度O(k)
 * n为amount值，k为coins数组大小
 */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (coins.empty())
            return -1;

        vector<int> dp(amount+1, amount+1);   // 初始值-1表示无法兑换
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                if (i>= coins[j])
                    dp[i] = min(dp[i], dp[i-coins[j]] + 1);
            }
        }
        return dp.back() == amount+1?-1:dp.back();
    }
};

int main(){
//    vector<int> coins = {1,2,5}; int amount = 11;
    vector<int> coins = {186,419,83,408}; int amount = 6249;
//    vector<int> coins = {2,4}; int amount = 3;
//    vector<int> coins = {1}; int amount = 0;
    Solution sol;
    cout << sol.coinChange(coins,amount) << endl;
    return 0;
}

