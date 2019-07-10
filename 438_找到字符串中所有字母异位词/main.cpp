#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 滑动窗口-双指针
 */
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        if(p.size() > s.size()) return ret;
        unordered_map<char, int> need;
        unordered_map<char, int> window;
        for(char c:p)        // 统计p的字符分布
            need[c] ++;
        int left = 0, right = 0;
        int match = 0;       // 匹配的字符数
        while (right < s.size()){
            char c1 = s[right];
            if(need.count(c1)){
                window[c1] ++;
                if(window[c1] == need[c1])
                    match ++;
            }
            right ++;

            while (match == need.size()){
                if(right - left == p.size())
                    ret.push_back(left);

                char c2 = s[left];
                if(need.count(c2)){
                    window[c2] --;
                    if(window[c2] < need[c2])
                        match--;
                }
                left++;
            }
        }

        return ret;
    }
};

int main(){
    string s = "abab", p = "ab";
    Solution sol;
    vector<int> ret = sol.findAnagrams(s,p);
    for (auto v:ret)
        cout << v <<" ";

    return 0;
}