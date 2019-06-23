#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 回溯
 */
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        if(n<1 || k<1) return ret;
        vector<int> curr;
        combineCore(1, n, k,curr,ret);
        return ret;
    }
    // 回溯
    void combineCore(int start, int n, int k, vector<int> &curr, vector<vector<int>> &ret){
        if(curr.size() == k)        // 当前长度达到k
            ret.push_back(curr);
        for (int i = start; i < n+1; ++i) {
            curr.push_back(i);  // 选取i位置元素
            combineCore(i+1, n,k, curr, ret);
            curr.pop_back();    // 恢复
        }
    }
};

int main(){
    int n = 4, k = 2;
    Solution sol;
    vector<vector<int>> ret = sol.combine(n,k);
    for (auto rows:ret){
        for (auto v:rows)
            cout << v <<" ";
        cout << endl;
    }
    return 0;
}