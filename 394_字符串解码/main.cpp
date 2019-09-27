#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 辅助栈方法
 * 时间复杂度：O(n) 空间复杂度O(n)
 * 解题关键是对于嵌套括号的处理，需要从内向外生成并拼接字符串，这与栈先先进后出的特性对应
 */
class SolutionI {
public:
    string decodeString(string s) {
        if(s.empty()) return s;
        stack<string> strStack;
        stack<int> numStack;
        string cur = "";  // cur当前数字跟随的字符串
        int num = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9')
                num = num * 10 + (s[i] - '0');
            else if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <='Z')){
                cur += s[i];
            }
            else if(s[i] == '['){
                numStack.push(num);
                strStack.push(cur);
                num = 0;
                cur = "";
            } else if(s[i] == ']'){
                int mul = numStack.top();
                numStack.pop();
                for (int j = 0; j < mul; ++j)
                    strStack.top() += cur;  // 后面拼接cur字符串
                cur = strStack.top();
                strStack.pop();
                num = 0;
            }
        }
        return cur;
    }
};

/*
 * 递归
 * 时间复杂度：O(n) 空间复杂度O(n)
 * 总体思路与辅助栈法一致，不同点在于将 [ 和 ] 分别作为递归的开启与终止条件：
 */
class Solution {
public:
    string decodeString(string s) {
        int pos = 0;
        return dfs(s,pos);
    }
private:
    // dfs返回子串和]所在的计数
    string dfs(string s, int &i ){
        string ret = "";
        while (i < s.size() && s[i]!=']'){  // 加上s[i]!=']'的目的是对于3[a]里对a后]判断结束返回
            if(s[i]< '0' || s[i] > '9') // 字符情况
                ret += s[i++];
            else{
                int num = 0;
                while(i < s.size() && s[i] >= '0' && s[i] <= '9')
                    num = num * 10 + (s[i++] - '0');
                ++i;    // [的下一个位位置
                string cur = dfs(s,i);
                ++i;    // ]的下一个位置
                while (num--)
                    ret += cur;
            }
        }
        return ret;
    }
};

int main(){
    Solution sol;
    string s = "3[a]2[bc]";
    cout << sol.decodeString(s) << endl;
}