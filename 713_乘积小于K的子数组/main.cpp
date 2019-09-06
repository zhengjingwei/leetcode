#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 给定一个正整数数组 nums。
 * 找出该数组内乘积小于 k 的连续的子数组的个数。
 */

// 滑动窗口双指针
// 时间复杂度O(n) 空间复杂度o(1)
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int left = 0;
        int prod = 1;   // 乘积
        int ret = 0;
        for(int right = 0; right < nums.size(); ++right){
            prod *= nums[right];
            while(prod >= k)
                prod /= nums[left++];
            ret += right - left +1; // 从[left..right]以right结尾的连续子数组个数
        }
        return ret;
    }
};

int main(){

}