#include <iostream>
#include <bits/stdc++.h>
using namespace std;


/*
 * 分治递归
 */
class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.empty() || s.size() < k ) return 0;
        if (k <=1) return s.size();

        unordered_map<char, int> m;
        for (char c:s)
            m[c] ++;

        int low = 0;
        int high = s.size() -1;
        // 删除开头和末尾出现次数<k的字符
        while (high - low + 1 >= k && m[s[low]] < k) ++ low;
        while (high - low + 1 >= k && m[s[high]] < k) --high;

        if(high - low + 1 < k) return 0;

        int i = low;
        while (i<high && m[s[i]] >= k) ++i;

        if(i == high) return high - low + 1;


        int left = longestSubstring(s.substr(low,i),k);
        int right = longestSubstring(s.substr(i,high),k);

        return max(left,right);
    }
};

int main(){
    string s = "ababbc";
    Solution sol;
    cout << sol.longestSubstring(s,2) << endl;
    return 0;
}

