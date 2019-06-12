#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 暴力
 * 时间复杂度O(nk) 空间复杂度O(n)
 * k为位1的平均个数
 */
class SolutionI {
public:
    vector<int> countBits(int num) {
        vector<int> ret = {0};
        for(int i = 1; i< num+1; ++i){
            int cnt = 0;
            int n = i;
            while(n!=0){
                ++ cnt;
                n = (n-1) & n;
            }
            ret.push_back(cnt);
        }
        return ret;
    }
};

/*
 * 动态规划
 * 时间复杂度O(n) 空间复杂度O(n)
 */
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret = {0};
        for(int i = 1; i< num+1; ++i){
            if (i & 0x01)
                ret.push_back(ret[i>>1]+1); // 或者ret[i-1]+1
            else
                ret.push_back(ret[i>>1]);
        }
        return ret;
    }
};

int main(){
    Solution sol;
    vector<int> ret = sol.countBits(5);
    for (auto n:ret)
        cout<<n<<" ";
//    cout << sol.countBits(5) << endl;
    return 0;
}

