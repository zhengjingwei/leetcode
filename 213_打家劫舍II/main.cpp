/*
 * 两次遍历
 * O(n)
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        int sumNminus2 = 0;
        int sumNminus1 = 0;
        int sum1 = 0;
        // 计算不包含首元素的最大收益
        for (int i = 1; i < nums.size(); ++i) {
            sum1 = max(sumNminus1, sumNminus2+nums[i]);
            sumNminus2 = sumNminus1;
            sumNminus1 = sum1;
        }

        // 计算不包含尾元素的最大收益
        int sum2 = 0;
        sumNminus1 = 0, sumNminus2 = 0;
        for (int i = 0; i < nums.size()-1; ++i) {
            sum2 = max(sumNminus1, sumNminus2+nums[i]);
            sumNminus2 = sumNminus1;
            sumNminus1 = sum2;
        }
        return max(sum1,sum2);
    }
};