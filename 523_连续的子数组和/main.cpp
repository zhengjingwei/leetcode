class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.empty()) return false;
        vector<int> sum(nums.size(),0);
        sum[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i)
            sum[i] = sum[i-1] + nums[i];    // 数组的累加和
        // 判断nums[i:j]是否符合
        for(int i = 0; i < nums.size()-1; ++i){
            for(int j = i+1; j < nums.size(); ++j){
                int s = sum[j] - sum[i] + nums[i];
                if( s == k || (k!=0 && s % k == 0))
                    return true;
            }
        }
        return false;
    }
};