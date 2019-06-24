#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 暴力回溯
 */
class SolutionI {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        if(n<1) return ret;
        string s = "";
        help(s,n*2,ret);
        return ret;
    }

private:
    void help(string s, int len, vector<string>& ret){
        if(s.size() == len){
            if(isValid(s))
                ret.push_back(s);
            return;
        }
        s.push_back('(');
        help(s,len,ret);
        s.pop_back();

        s.push_back(')');
        help(s,len,ret);
        s.pop_back();
    }

    bool isValid(string s){
        int cnt = 0;        // 括号的数量减去右括号的数量的净值
        for (auto ch:s){    // 如果这个值始终小于零或者不以零结束，该序列就是无效的，否则它是有效的。
            if(ch == '(')
                cnt++;
            else
                cnt--;
            if(cnt<0)
                return false;
        }
        return cnt == 0;
    }
};

/*
 * 回溯
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        if(n<1) return ret;
        string s = "";
        help(s,0,0,n,ret);
        return ret;
    }

private:
    // left：左括号数量，right：右括号数量
    void help(string s,int left, int right, int n, vector<string>& ret){
        if(s.size() == n*2){
            ret.push_back(s);
            return;
        }
        if(left<n)
            help(s+"(", left+1, right,n,ret);
        if(right<left)
            help(s+")", left, right+1,n, ret);
    }
};

int main(){
    Solution sol;
    vector<string> s = sol.generateParenthesis(3);
    for (auto ss:s)
        cout<< ss <<endl;
    return 0;
}