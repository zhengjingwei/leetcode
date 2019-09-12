// 一维动态规划 时间复杂度O(n)
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        int maxProd = nums[0]*nums[1];  // 两个数的最大乘积
        int minProd = nums[0]*nums[1];  // 两个数的最小乘积
        int minVal = min(nums[0],nums[1]);  // 当前最小值
        int maxVal = max(nums[0],nums[1]);  // 当前最大值
        int ret = INT_MIN;
        for(int i = 2; i< nums.size(); ++ i){
            ret = max(ret, max(maxProd*nums[i], minProd*nums[i]));  // 三个数最大乘积来源：两个数最大乘积/最小乘积与当前数的乘积
            maxProd = max(maxProd, max(maxVal * nums[i], minVal * nums[i]));
            minProd = min(minProd, min(maxVal * nums[i], minVal * nums[i]));
            minVal = min(minVal, nums[i]);
            maxVal = max(maxVal, nums[i]);
        }
        return ret;
    }
};