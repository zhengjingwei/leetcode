// 给定一个整数数组 nums ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）。
/*
 * 以当前元素nums[i]结尾的最大乘积和有三种可能
 * nums[i-1]结尾的最大乘积和*nums[i], nums[i-1]结尾的最小乘积和*nums[i], nums[i]
 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int maxEnd = 0;
        int minEnd = 0;
        int maxVal = nums[0];   // 以当前元素结尾的最大累乘积
        int minVal = nums[0];   // 以当前元素结尾的最小累乘积
        int ret = nums[0];
        for (int i = 1; i < nums.size(); ++i){
            maxEnd = maxVal * nums[i];
            minEnd = minVal * nums[i];
            maxVal = max(max(maxEnd, minEnd), nums[i]);
            minVal = min(min(maxEnd, minEnd), nums[i]);
            ret = max(maxVal, ret);
        }
        return ret;
    }
};