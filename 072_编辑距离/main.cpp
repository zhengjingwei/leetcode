#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 编辑距离
 * 动态规划
 * 时间复杂度O(mn) 空间复杂度O(mn)
 */
class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.empty()) return word2.size();
        if(word2.empty()) return word1.size();

        int len1 = word1.size(), len2 = word2.size();

        vector<vector<int>> dp(len1+1, vector<int>(len2+1,0));
        for (int i = 0; i < len1+1; ++i) dp[i][0] = i;  // 字符串1长度为i与空串距离
        for (int j = 0; j < len2+1; ++j) dp[0][j] = j;  // 字符串2长度为j与空串距离

        for (int i = 1; i < len1+1; ++i) {
            for (int j = 1; j < len2+1; ++j) {
                dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1);
                dp[i][j] = min(dp[i][j] , dp[i-1][j-1] + (word1[i-1] != word2[j-1]));
            }
        }
        return dp.back().back();
    }
};

int main(){
//    string s1 =  "horse", s2 = "ros"; // 3
    string s1 = "intention", s2 = "execution";  // 5
    Solution sol;
    cout << sol.minDistance(s1,s2) << endl;
    return 0;
}

