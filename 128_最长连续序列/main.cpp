#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 排序后查找
 * 时间复杂度O(n^2)  空间复杂度O(1)
 */
class SolutionI {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        sort(nums.begin(),nums.end());

        int maxLen = 1, currentLen =1;
        for (int i = 1; i < nums.size(); ++i) {
            if(nums[i] == nums[i-1]+1)
                currentLen += 1;
            else if(nums[i] == nums[i-1])
                continue;
            else
                currentLen = 1;
            maxLen = max(maxLen,currentLen);
        }
        return maxLen;
    }
};

/*
 *  哈希表和线性空间构造
 *  时间复杂度O(n)   空间复杂度O(n)
 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        set<int> s;
        for(auto num:nums) s.insert(num);   // 构建集合

        int maxLen = 0, currentLen = 0;
        for (int num:s) {
            // 只检查num-1不在集合中的元素
            if(s.count(num-1) == 0){
                int currentNum = num;
                currentLen = 1;

                while (s.count(currentNum+1)){  // 往后查找元素是否存在
                    currentLen ++;
                    currentNum ++;
                }
                maxLen = max(maxLen,currentLen);
            }
        }

        return maxLen;
    }
};

int main(){
//    vector<int> nums = {100, 4, 200, 1, 3, 2}; // 4
    vector<int> nums = {1,2,0,1}; // 3
    Solution sol;
    cout << sol.longestConsecutive(nums) << endl;
    return 0;
}

