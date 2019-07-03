#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;   // 记录已经出现的组合
        n = digitSquareSum(n);
        while (n!=1){
            if(s.find(n) != s.end())    // 出现循环
                return false;
            s.insert(n);
            n = digitSquareSum(n);
        }
        return true;
    }

private:
    int digitSquareSum(int n){
        int ret = 0;
        while (n>0){
            ret += (n % 10) * (n % 10);
            n /= 10;
        }
        return ret;
    }
};


int main(){
    Solution sol;
    cout << sol.digitSquareSum(82) << endl;
    return 0;
}

