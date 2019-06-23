#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 回溯
 */
class Solution {
    vector<int> candidates = {1,2,3,4,5,6,7,8,9};
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ret;
        vector<int> curr;
        if(n<1 || k < 1 || n>(1+9)*9/2 || k > 9) return ret;    // 小于0或超过表示范围
        combinationSum3Core(k,n,0,curr,ret);
        return ret;
    }
    void combinationSum3Core(int k, int n, int begin, vector<int>& curr, vector<vector<int>>& ret){
        if(n < 0) return;
        if(n == 0){
            if(curr.size() == k)            // 和为n并且个数为k
                ret.push_back(curr);
            return;
        } else{
            if(curr.size() >= k) return;    // 组合数字个数超过k
            for (int i = begin; i < candidates.size(); ++i) {
                curr.push_back(candidates[i]);
                combinationSum3Core(k,n-candidates[i], i+1, curr, ret);
                curr.pop_back();
            }
        }
    }
};

int main(){
    int k = 3, n = 9;
    Solution sol;
    vector<vector<int>> ret = sol.combinationSum3(k,n);
    for (auto rows:ret){
        for (auto v:rows)
            cout << v <<" ";
        cout << endl;
    }
    return 0;
}