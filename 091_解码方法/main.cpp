class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0 || (s.size() == 1 && s[0] == '0')) return 0;   // 0不能解码
        if(s.size() == 1) return 1;
        vector<int > dp(s.size() ,0);
        dp[0] = s[0] == '0' ? 0:1;
        for (int i = 1; i < s.size(); ++i) {
            if(s[i] == '0') // 0不能单独解码
                dp[i] = 0;
            else
                dp[i] = dp[i-1];
            int x = s[i-1] - '0';
            int y = s[i] - '0';
            int num = x * 10 + y;
            if(num >= 10 && num <= 26)
                dp[i] += i>1? dp[i-2] :1;
        }
        return dp.back();
    }
};