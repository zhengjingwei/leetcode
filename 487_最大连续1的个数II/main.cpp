// 滑动窗口
// 时间复杂度：O（n）空间复杂度：O（1）
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int zeros = 0;  // 窗口内0个数
        int l = 0, r = 0, ret = 0;
        while(r < nums.size()){
            if(nums[r] == 0)
                zeros++;
            while(zeros>1){
                if(nums[l++] == 0)
                    zeros--;
            }
            ret = max(ret, r -l+1);
            r++;
        }
        return ret;
    }
};