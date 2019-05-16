#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int ret = 0;
        for(auto ch:s)
            ret =  ret * 26 + (ch - 'A') + 1;
        return ret;
    }
};


int main(){
    string s = "AB";    // 28
//    string s = "ZY";    // 701
    Solution sol;
    cout << sol.titleToNumber(s) << endl;
    return 0;
}

