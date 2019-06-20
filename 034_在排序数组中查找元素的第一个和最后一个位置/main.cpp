#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret = {-1,-1};
        if(nums.empty()) return ret;

        int left = 0, right = nums.size();
        // 寻找最左坐标
        while(left < right){
            int mid = (left + right) /2;
            if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        if(left >= nums.size() || nums[left]!=target) return ret;
        ret[0] = left;

        // 寻找最右坐标
        left = 0, right = nums.size();
        while(left < right){
            int mid = (left + right) /2;
            if(nums[mid] <= target)
                left = mid + 1;
            else
                right = mid;
        }

        ret[1] = right-1;
        return ret;
    }
};


int main(){
    Solution sol;
//    vector<int> nums = {1};
//    int target = 1;
//    vector<int> nums = {5,7,7,8,8,8,10};
//    int target = 8;
    vector<int> nums = {2,2};
    int target = 3;
    vector<int> ret = sol.searchRange(nums, target);
    cout<< ret[0] << " " << ret[1] <<endl;
    return 0;
}