#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
 * 动态规划
 * dp[i][j]表示s1前i个项和s2前j项能否组成s3前i+j项
 */
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size())
            return false;
        vector<vector<bool >> dp(s1.size() + 1, vector<bool> (s2.size() +1, false));
        dp[0][0] = true;   // 空串和空串
        // s2不参与情况下；能否只由s1构成
        for (int i = 0; i < s1.size(); ++i){
            if(s1[i]!= s3[i])
                break;
            dp[i+1][0] = true;
        }
        // s1不参与情况下
        for (int i = 0; i < s2.size(); ++i){
            if(s2[i]!= s3[i])
                break;
            dp[0][i+1] = true;
        }

        for (int i = 1; i <= s1.size() ; ++i) {
            for (int j = 1; j <= s2.size() ; ++j) {
                if((dp[i-1][j] && s1[i-1] == s3[i+j-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1]))
                    dp[i][j] = true;
            }
        }

        return dp.back().back();
    }
};

int main(){
    string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
    Solution sol;
    cout << sol.isInterleave(s1,s2,s3) << endl;
}

