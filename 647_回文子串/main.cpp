#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 暴力
 * 时间复杂度O(n^3) 空间复杂度O(1)
 */
class SolutionI {
public:
    int countSubstrings(string s) {
        if(s.empty()) return 0;
        int ret = 0;
        for(int i = 0; i<s.size(); ++i){
            for(int j = i; j<s.size(); ++j){
                if (isPalindrome(s,i,j))
                    ++ ret;
            }
        }
        return ret;
    }
    bool isPalindrome(string s, int i, int j){
        while(i<=j){
            if(s[i++]!=s[j--])
                return false;
        }
        return true;
    }
};

/*
 * 动态规划
 * 时间复杂度O(n^2) 空间复杂度O(n^2)
 */
class Solution {
public:
    int countSubstrings(string s) {
        if(s.empty()) return 0;
        int len = s.size();
        vector<vector<bool >> dp(len, vector<bool > (len, false));
        int ret = 0;

        // 首先处理长度为1和2的子串
        for (int i = 0; i < len; ++i) {
            dp[i][i] = true;            // 初始化长度为1的回文串
            ++ ret;
        }
        for (int i = 0; i< len -1; ++i){
            if (s[i] == s[i+1]){
                dp[i][i+1] = true;      // 初始化长度为2的回文串
                ++ ret;
            }
        }

        // i为遍历的子串长度,j为起始节点
        for (int i = 3; i <= len ; ++i) {
            for (int j = 0; j <= len -i + 1; ++j) {
                int end = j+i-1;
                if(s[j] == s[end] && dp[j+1][end-1]){
                    dp[j][end] = true;
                    ++ ret;
                }
            }
        }
        return ret;
    }
};

/*
 * 中心字符扩展
 * 时间复杂度O(n) 空间复杂度O(1)
 */
class SolutionII {
public:
    int countSubstrings(string s) {
        if(s.empty()) return 0;
        int ret = 0;
        for(int i = 0; i<s.size(); ++i){
            count(s,i,i,ret);       // 以i位置字符为中心，长度为奇数的回文串数目
            count(s,i,i+1,ret);     // 以i,i+1位置字符为中心，长度为偶数的回文串数目
        }
        return ret;
    }

    void count(string &s, int begin, int end, int &ret){
        while (begin>=0 && end<s.size() && s[begin--] == s[end++])
            ++ ret;
    }
};

int main(){
    string s = "aaaaa";
    Solution sol;
    cout<<sol.countSubstrings(s)<<endl;
    return 0;
}

