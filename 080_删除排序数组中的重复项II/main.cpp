#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2)
            return nums.size();
        int curr = 1;   // 新数组中有效位置的最后一位，新加入的数据应当写到curr+1
        for (int i = 2; i < nums.size(); ++i) { // 前2个必定符合，从第三个开始遍历
            if(nums[i] != nums[curr-1]){
                curr ++;
                nums[curr] = nums[i];
            }
        }
        return curr + 1;
    }
};
