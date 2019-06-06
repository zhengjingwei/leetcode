#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 动态规划
 * 时间复杂度O(N) 空间复杂度O(1)
 */
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        int maxLen = 1, currentLen = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i-1])    // 如果大于上一元素 f(i) = f(i-1) + 1
                currentLen += 1;
            else
                currentLen = 1;
            maxLen = currentLen > maxLen?currentLen:maxLen;
        }
        return maxLen;
    }
};

int main(){
    vector<int> nums = {1,3,5,4,7};
    Solution sol;
    cout << sol.findLengthOfLCIS(nums) << endl;
    return 0;
}

