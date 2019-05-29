#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * 二分查找；大的那一半区间一定会有峰值
     */
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() -1;
        while (left <right){
            int mid = (left + right) /2;
            if (mid > 0 && nums[mid] < nums[mid - 1])
                right = mid - 1;
            else if (mid < nums.size()-1 && nums[mid] < nums[mid +1])
                left = mid + 1;
            else
                return mid;
        }
        return left;
    }
};

int main(){
    vector<int> nums = {1,2,3,1};
    Solution sol;
    cout<< sol.findPeakElement(nums)<< endl;
    return 0;
}

