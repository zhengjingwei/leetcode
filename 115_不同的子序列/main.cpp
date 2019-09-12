class Solution {
public:
    int numDistinct(string s, string t) {
        // dp[i][j]表示s前j个元素能匹配t前j个的最多个数
        vector<vector<unsigned long>> dp(s.size()+1, vector<unsigned long> (t.size()+1, 0));
        for (int i = 0; i<= s.size(); ++i) {
            dp[i][0] = 1;   // 空集是所有字符串子集
        }
        for(int i = 1; i <= s.size(); ++i){
            for(int j = 1; j <= t.size(); ++j){
                if(s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];   // 前i-1个s匹配j个t + 前i个匹配j个t
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp.back().back();
    }
};