#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * multiset(自动排序)+更新中间位置迭代器
 * 时间复杂度：O(n log k)
 */
class SolutionI {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window(nums.begin(), nums.begin() + k);
        // multiset自带排序功能，所以我们通过k/2能快速的找到指向最中间的数字的迭代器mid
        auto mid = next(window.begin(), k / 2);
        vector<double > ret;
        ret.push_back((double(*mid) + *prev(mid, 1 - k % 2)) / 2);

        for (int i = k; i < nums.size(); ++i) {
            // 插入nums[i]元素
            window.insert(nums[i]);
            if(nums[i] < *mid)
                mid --;
            if(nums[i-k] <= *mid)
                mid ++;
            // 删除nums[i-k]元素
            window.erase(window.lower_bound(nums[i-k]));    // 将滑动窗口最左边的数删掉
            ret.push_back((double(*mid) + *prev(mid, 1 - k % 2)) / 2);
        }

        return ret;
    }
};

/*
 * 维护最大堆和最小堆
 * 最大堆的元素数不少于最小堆，并且相差不大于1
 */
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int, less<int>> minHeap;
        multiset<int, greater<int>> maxHeap;

        vector<double > ret;
        for (int i = 0; i < nums.size(); ++i) {
            if ( i>= k){
                // 删除窗口最左边元素
                if(maxHeap.count(nums[i-k]))
                    maxHeap.erase(maxHeap.lower_bound(nums[i-k]));
                else if(minHeap.count(nums[i-k]))
                    minHeap.erase(minHeap.lower_bound(nums[i-k]));
            }

            if(maxHeap.empty() || nums[i] < *maxHeap.begin())
                maxHeap.insert(nums[i]);
            else
                minHeap.insert(nums[i]);

            // 保持最大堆数目不小于最小堆；并且相差最多为1
            while (maxHeap.size() > minHeap.size() + 1){
                minHeap.insert(*maxHeap.begin());
                maxHeap.erase(maxHeap.begin());
            }
            while (maxHeap.size() < minHeap.size()){
                maxHeap.insert(*minHeap.begin());
                minHeap.erase(minHeap.begin());
            }

            if ( i >= k-1){
                if (k % 2)
                    ret.push_back(*maxHeap.begin());
                else
                    ret.push_back(((double) *maxHeap.begin() + *minHeap.begin())/2);
            }
        }

        return ret;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,1,1,1};
    vector<double > ret = sol.medianSlidingWindow(nums, 2);
//    vector<int> nums = {1,2,3,4,2,3,1,4,2};
//    vector<double > ret = sol.medianSlidingWindow(nums, 3);
    for (auto v:ret)
        cout << v << " ";
    return 0;
}