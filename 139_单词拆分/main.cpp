class Solution {
public:
    // 动态规划。dp[i]表示字符串s的前i个字符能否拆分成wordDict
    // 如果d[j]=true && (i-j)组成的字符串在字典中，则d[i]=true
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1, false);
        unordered_set<string> m(wordDict.begin(), wordDict.end());
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if(dp[j] && (m.find(s.substr(j,i-j))!=m.end())){
                    dp[i] = true;
                    break;
                }
            }

        }
        return dp[s.size()];    // 前n个字符能否拆分
    }
};
