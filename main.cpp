class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m+1,vector<bool>(n+1, false));
        dp[0][0] = true;

        for (int j = 1; j <= n ; ++j)
            dp[0][j] = dp[0][j-1] && p[j-1] == '*'; // p前j个字符都是*都作为空串，则为1

        for (int i = 1; i <= s.size() ; ++i) {
            for (int j = 1; j <= p.size(); ++j) {
                if (p[j - 1] == '?' || p[j - 1] == s[i - 1])
                    dp[i][j] = dp[i - 1][j - 1];    // 一个一个匹配
                else if (p[j - 1] == '*')
                    dp[i][j] = dp[i - 1][j]       // * 匹配任意字符
                               || dp[i][j - 1];      // * 匹配空串
            }
        }
        return dp[s.size()][p.size()];
    }
};