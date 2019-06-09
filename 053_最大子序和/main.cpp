#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
 * 动态规划
 * 时间复杂度O(n) 空间复杂度O(1)
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        int currentSum = nums[0];
        int maxSum = nums[0];
        for (int i = 1; i < nums.size(); ++i){
            currentSum = currentSum > 0? nums[i]+currentSum: nums[i];
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
    }
};

/*
 * 分治
 * 时间复杂度O(nlogn) 空间复杂度O(1)
 */
class SolutionII {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        return help(nums,0,nums.size()-1);
    }

    int help(vector<int>& nums, int left, int right){
        if(left == right)
            return nums[left];
        if(left > right)
            return INT_MIN;
        int mid = (left+right)/2;
        int leftSum = help(nums,left,mid-1);
        int rightSum = help(nums,mid+1,right);

        // 计算穿过中间的最大子序和
        int midSumLeft = 0;     // 初始值为0 未选择任何左序列
        int midSumRight = 0;
        int tmp = 0;
        for (int i = mid-1; i >= left; --i) {
            tmp += nums[i];
            midSumLeft = max(midSumLeft, tmp);
        }
        for (int i = mid+1,tmp = 0; i <= right ; ++i) {
            tmp += nums[i];
            midSumRight = max(midSumRight, tmp);
        }

        return max(max(leftSum,rightSum), midSumLeft+midSumRight+nums[mid]);
    }
};

int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4}; // 6
    SolutionII sol;
    cout << sol.maxSubArray(nums) << endl;
    return 0;
}

