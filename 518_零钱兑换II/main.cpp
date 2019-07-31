// 动态规划
// 时间复杂度O（mn） 空间复杂度O（mn）
// dp[i][j] = dp[i-1][j] + dp[i-1][j-coin[i]]
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount == 0 ) return 1;
        else if (coins.empty()) return 0;
        // dp[i][j]表示前i个硬币组合成j的组合数
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, 0));
        for (int i = 0; i < coins.size(); ++i)
            dp[i][0] = 1;   // 注意amount=0初始化为1
        for (int j = 1; coins[0] * j <= amount; ++j)
            dp[0][coins[0] * j] = 1;    // 只用第一种硬币
        for (int i = 1; i < coins.size(); ++i){
            for (int j = 1; j <= amount; ++j){
                dp[i][j] = dp[i-1][j];  // 不使用coin[i]
                dp[i][j] += j-coins[i] >=0 ? dp[i][j-coins[i]] : 0;
            }
        }
        
        return dp.back().back();
    }
};


// 优化后的动态规划
// 时间复杂度O（mn） 空间复杂度O（m） m为金额
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount == 0 ) return 1;
        else if (coins.empty()) return 0;
        // dp[i][j]表示前i个硬币组合成j的组合数
        vector<int> dp(amount+1);
        dp[0] = 1;
        for (int j = 1; coins[0] * j <= amount; ++j)
            dp[coins[0] * j] = 1;    // 只用第一种硬币
        for (int i = 1; i < coins.size(); ++i){
            for (int j = 1; j <= amount; ++j){
               dp[j] +=  j-coins[i] >=0 ? dp[j-coins[i]] : 0;
            }
        }
        
        return dp.back();
    }
};