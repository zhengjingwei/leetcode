#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 座位交换法
 */
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        // 把num[i]放到nums[i]-1的位置上；最多循环内最多2n次
        for (int i = 0; i < nums.size(); ++i) {
            // 最后的条件保证不重复交换
            while (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i]-1])
                swap(nums[i], nums[nums[i] -1]);
        }
        for (int i = 0; i < nums.size(); ++i) {
            if(nums[i]!=i+1)
                return i+1;
        }
        return nums.size()+1;
    }
};


int main(){
    vector<int> nums = {1,2,0};
    Solution sol;
    cout << sol.firstMissingPositive(nums) << endl;
    return 0;
}