#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())
            return -1;
        int len = nums.size();
        int index = findRotateIndex(nums);
        if (index == 0)
            return binarySearch(nums,0, len -1, target); // 是正常排序序列
        if (nums[index] == target) return index;    // 注意在旋转坐标需要单独判断
        if (nums[0] <= target)
            return binarySearch(nums, 0, index -1, target);
        else
            return binarySearch(nums, index, len -1, target);
    }

    // 正常的二分查找
    int binarySearch(vector<int>& nums, int left, int right, int target){
//        if(left > right) return -1;
        while (left <= right){
            int mid = (left + right) /2;
            if (nums[mid] == target)
                return mid;
            else if (target<nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }

private:
    // 二分查找旋转点
    int findRotateIndex(vector<int>& nums){
        if(nums.front() <= nums.back())
            return 0;

        int left = 0, right = nums.size() -1;
        while (left <= right){
            int mid = (left + right) /2;
            if (nums[mid+1] < nums[mid] )
                return mid+1;
            if (nums[mid] < nums[left])
                right = mid -1;
            else
                left = mid + 1;
        }
        return 0;
    }
};



int main(){
//    vector<int> nums = {4,5,6,7,0,1,2};
//    int target = 0;
//    vector<int> nums = {8,9,2,3,4};
//    int target = 9;
    vector<int> nums = {8,2,5};
    int target = 5;
    Solution sol;
    cout <<sol.search(nums, target) << endl;
    return 0;
}