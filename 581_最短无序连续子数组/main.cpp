// 以[2,6,4,8,10,9,15]为例 需要找到6和9对应的位置
// 6代表的是比其右边最小值要大的最左位置
// 9代表的是比其左边最大值要小的最右位置
// 两个位置之间的区间是需要进行排序的最短区间
// 时间复杂度O(n) 空间复杂度O(1)
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        int n = nums.size();
        int minVal = nums[n-1]; // 从右往左遍历过程中当前最小值
        int noMinIndex = -1;    // 不满足当前元素<minVal的最左位置
        for(int i = n-2; i >=0; --i){
            if(nums[i] > minVal)
                noMinIndex = i;
            else
                minVal = nums[i];
        }
        if(noMinIndex == -1) return 0;  // 原数组有序
        int maxVal = nums[0];   // 从右往左遍历过程中当前最大值
        int noMaxIndex = -1;    // 不满足当前元素>maxVal的最右位置
        for(int i = 1; i < n; ++i){
            if(nums[i] < maxVal)
                noMaxIndex = i;
            else
                maxVal = nums[i];
        }
        return noMaxIndex - noMinIndex +1;
    }
};