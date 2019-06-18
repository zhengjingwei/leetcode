#include <iostream>
#include <bits/stdc++.h>
using namespace std;




class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";

        string s;
        for (int i = num2.size() -1; i>=0; --i) {
            string zeros(num2.size() -1 - i,'0');   // 补零
            string tmp = help(num1, num2[i]) + zeros;
            s = addStrings(s, tmp);
        }
        return s;
    }

    // 一个数字和一串数字相乘
    string help(string num, char c){
        if(c == '0') return "0";
        string s;
        int carry = 0;
        for(int i = num.size() -1; i>=0 || carry >0; --i){
            int x = i >= 0? num[i] - '0': 0;
            int y = c - '0';
            s.push_back((x * y + carry) % 10 + '0');
            carry = (x * y + carry) / 10;
        }
        reverse(s.begin(),s.end());
        return s;
    }

private:
    // 两个字符串相加
    string addStrings(string num1, string num2){
        if(num1.empty())
            return num2;
        if(num2.empty())
            return num1;
        string s;
        int carry = 0;
        for (int i = num1.size() -1, j = num2.size()-1; i>=0 || j>=0 || carry > 0 ; --i, --j) {
            int x = i < 0 ? 0 : num1[i] - '0';
            int y = j < 0 ? 0 : num2[j] - '0';
            s.push_back((x+y+carry)%10 + '0');
            carry = (x+y+carry)/10;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};
int main(){
    Solution sol;
    string s = "123";
    string num1 = "9", num2 = "9";
//    string num1 = "123", num2 = "456";
    cout << sol.multiply(num1,num2) << endl;

    return 0;
}