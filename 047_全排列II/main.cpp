#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 回溯
 */
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        if(nums.empty()) return ret;
        sort(nums.begin(), nums.end());
        permuteUniqueCore(nums,0,ret);
        return ret;
    }

private:
    void permuteUniqueCore(vector<int> nums, int begin, vector<vector<int>>& ret){
        if(begin>= nums.size()){                    // 到达最后元素，打印
            ret.push_back(nums);
            return;
        }
        for (int i = begin; i < nums.size(); ++i) {
            if(i!=begin && nums[i] == nums[begin])   // 如果后续有重复数字 不需要交换
                continue;
            swap(nums[i],nums[begin]);
            permuteUniqueCore(nums, begin+1, ret);  // begin+1递归
        }
    }
};

int main(){
    Solution sol;
    vector<int > nums = {1,1,2,2};
    vector<vector<int>> ret = sol.permuteUnique(nums);
    for (auto rows:ret){
        for (auto n:rows) {
            cout<<n<<" ";
        }
        cout<<endl;
    }
    return 0;
}