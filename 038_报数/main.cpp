#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 1; i < n; ++i) {
            string tmp;
            char c = s[0];
            int cnt = 0;
            for (int j = 0; j < s.size(); ++j) {
                if(s[j] == c){
                    cnt ++;
                }
                else{
                    tmp += to_string(cnt) + c;
                    c = s[j];
                    cnt = 1;
                }
                if(j+1 == s.size())
                    tmp += to_string(cnt) + c;
            }
            s = tmp;
        }
        return s;
    }
};

int main(){
    Solution sol;
    cout <<sol.countAndSay(5) <<endl;
    return 0;
}