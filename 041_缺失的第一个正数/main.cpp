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

// 利用座位交换的思想
// 时间复杂度O(n) 空间复杂度O(1)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int l = 0;              // [1,l]表示已经出现的整数
        int r = nums.size();    // [l+1,r]表示可能出现的整数范围
        while(l < r){
            if(nums[l] == l+1)
                ++l;    // 第l位置的元素放置正确
            else if(nums[l] < l+1 || nums[l] > r || nums[nums[l]-1] == nums[l] ){
                // 已出现 or 超出可能范围 or 已经排好位置(出现重复元素)
                // 则代表可能出现的整数范围少一个,将最后一个位置元素赋值到当前位置,r-1
                nums[l] = nums[--r];
            }
            else{
                // nums[l]处于[l+1,r]范围内，将其与对应位置元素交换
                swap(nums[l], nums[nums[l]-1]); // 将nums[l]放置到nums[l]-1的位置   
            }  
        }
        return l+1; // l+1是未出现的第一个正数
    }
};

int main(){
    vector<int> nums = {1,2,0};
    Solution sol;
    cout << sol.firstMissingPositive(nums) << endl;
    return 0;
}