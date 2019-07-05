#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// 优化后的版本 20ms
class SolutionI {
public:
    bool isMatch(string s, string p) {
        return isMatch(s.c_str(), p.c_str());
    }

    bool isMatch(const char* s, const char* p) {
        if(*p == 0) return *s == 0;

        auto first_match = *s && (*s == *p || *p == '.');

        if(*(p+1) == '*'){
            return isMatch(s, p+2) || (first_match && isMatch(++s, p));
        }
        else{
            return first_match && isMatch(++s, ++p);
        }
    }
};

class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty())
            return s.empty();
        // 当前字符匹配
        bool first_match = !s.empty() && (p[0] == s[0] || p[0] == '.');

        // 下一个模式字符是*
        if(p.size() >= 2 && p[1] =='*'){
            return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));
        } else{
            return first_match && isMatch(s.substr(1), p.substr(1));
        }
    }
};


int main(){
    Solution sol;
    string s = "a", p = "ab";
//    string s = "aab", p = "c*a*b"; // true
    cout<<sol.isMatch(s,p)<<endl;
    return 0;
}