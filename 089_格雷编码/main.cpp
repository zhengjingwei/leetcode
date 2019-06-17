#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 迭代求解
 * 在上一组里全部尾后补0再倒序全部补1
 * 时间复杂度 O(n*2^n)
 */
class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 0) return vector<int> {0};
        vector<int> ret = {0,1};

        for (int i = 2; i <= n; ++i) {
            int len = ret.size();
            for (int j = 0; j < len; ++j)
                ret [j] = ret[j] << 1;    // 末位加一个0
            for (int j = len-1; j>=0 ; --j)
                ret.push_back(ret[j]+1);    // 末位加一个1
        }
        return ret;
    }
};

/*
 * 公式求解
 * 时间复杂度 O(2^n)
 */
class SolutionII {
public:
    vector<int> grayCode(int n) {
        vector<int> ret(1<<n);
        for (int i = 0; i< (1<<n); ++i)
            ret[i] = i^(i >> 1);
        return ret;
    }
};


int main(){
    SolutionII sol;
    vector<int > ret = sol.grayCode(3);
    for (auto n:ret)
        cout<< n<<" ";
    return 0;
}