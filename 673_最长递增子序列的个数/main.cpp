// 动态规划
// 时间复杂度：O(n^2)
// 空间复杂度：O(n)
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        int maxLen = 1;                     // 最长递增子序列长度和个数
        vector<int> len(nums.size(), 1);    // len[i]以i结尾的最长递增子序列
        vector<int> count(nums.size(), 1);  // count[i]以i结尾的最长递增子序列的个数
        for(int i = 1; i < nums.size(); ++i){
            for(int j = i-1; j >= 0 ; -- j){
                if(nums[i] > nums[j]){
                    if(len[i] < len[j]+1){          // 更新最大长度子序列
                        count[i] = count[j];
                        len[i] = len[j]+1;
                    }else if(len[i] == len[j] +1){  // 同样以i结尾的最大长度的子序列
                        count[i] += count[j];
                    }
                }
                maxLen = max(maxLen, len[i]);
            }
        }
        // 找到对应最大长度的计数
        int ret = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(len[i] == maxLen)
                ret += count[i];
        }
        return ret;
    }
};