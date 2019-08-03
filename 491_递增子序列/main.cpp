#include <iostream>
#include <bits/stdc++.h>
using namespace std;


/*
 * 给定一个整型数组, 你的任务是找到所有该数组的递增子序列，递增子序列的长度至少是2。
 * DFS
 */
class Solution {
    set<vector<int>> ret;   // 去重
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> cur;
        dfs(nums,cur,0);
        return vector<vector<int>>(ret.begin(), ret.end());
    }

private:
    void dfs(vector<int>& nums, vector<int>& cur, int k){
        if(k == nums.size()){
            return;
        }
        for (int i = k; i < nums.size(); ++i) {
            if(cur.empty() || nums[i] >= cur.back()){
                cur.push_back(nums[i]);
                dfs(nums, cur, i+1);
                if (cur.size() > 1)
                    ret.insert(cur);
                cur.pop_back();
            }
        }
    }
};

int main(){
    vector<int> nums = {4, 6, 7, 7};
    Solution sol;
    vector<vector<int>> ret = sol.findSubsequences(nums);
    for(auto line : ret){
        for (auto v : line)
            cout << v <<" ";
        cout << endl;
    }
}

