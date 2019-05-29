#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * 将数组看成链表，val是节点值也是下个节点的地址
     * 问题转换为判断链表有环
     * 时间复杂度O（n）
     */
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        // 当快慢指针相遇则在环内，但不一定是在环的入口相遇
        for (int fast = 0; slow != fast || fast == 0 ; ) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        // 确定环的入口
        for (int i = 0; i!=slow ; i = nums[i]) {
            slow = nums[slow];
        }
        return slow;
    }
};

class SolutionII {
public:
    /*
     * 二分查找+鸽笼原理
     * 时间复杂度O（nlog n）
     */
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size(); // 1和n
        while(low < high){
            int mid = (low + high) /2;
            int cnt = 0;
            //计算区间[l,mid]之间有多少个数
            for (auto num:nums) {
                if (num <= mid) ++cnt;
            }
            //区间[l,mid]之间应该有mid个数，若大于这个数，
            //那证明[1,mid]之间一定有重复的，所以搜索区间缩小为[l,mid]
            if (cnt > mid)
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};

int main(){
    vector<int> nums = {1,3,4,2,2};
    SolutionII sol;
    cout<< sol.findDuplicate(nums)<< endl;
    return 0;
}

