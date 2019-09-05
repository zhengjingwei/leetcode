// 前缀和数组
// 时间复杂度O(n) 空间复杂度O(n)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;  // (sum, count) 累计和计数
        m[0] = 1;
        int sum = 0; 
        int ret = 0; // 和为k的子数组计数
        for(int i = 0; i < nums.size(); ++ i){
            sum += nums[i];
            if(m.count(sum - k))
                ret += m[sum-k];
            m[sum] += 1;
        }
        return ret;
    }
};