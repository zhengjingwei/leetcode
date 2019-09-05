// 动态规划
// 时间复杂度O(mn) 空间复杂度O(mn)
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        if(A.empty()||B.empty()) return 0;
        int m = A.size(), n = B.size();
         // dp[i][j]表示以A以i位置结尾的子串与B以j位置结尾子串的最大重复长度
        vector<vector<int>> dp(m, vector<int>(n, 0));   
        int maxLen = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j<n; ++j){
                if(A[i] == B[j])
                    dp[i][j] = (i == 0 || j == 0) ? 1 :dp[i-1][j-1]+1;
                maxLen = max(maxLen, dp[i][j]);
            }
        }

        return maxLen;
    }
};