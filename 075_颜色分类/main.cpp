// class Solution {
// public:
//     // 两遍扫描 时间复杂度O(n) 空间复杂度O(1)
//     void sortColors(vector<int>& nums) {
//         int cnt[3] = {0};
//         for(auto n:nums){
//             cnt[n] += 1;
//         }
//         fill(nums.begin(), nums.begin() + cnt[0], 0);
//         fill(nums.begin() + cnt[0], nums.begin() + cnt[0]+cnt[1], 1);
//         fill(nums.begin() + cnt[0] + cnt[1], nums.end(), 2);
//     }
// };

class Solution {
public:
    // 荷兰国旗问题
    // 时间复杂度O(n) 空间复杂度O(1)
    void sortColors(vector<int>& nums) {
        if (nums.size() <= 1) return;
        // 对于所有 idx < p0 : nums[idx < p0] = 0
        // 对于所有 idx > p2 : nums[idx > p2] = 2
        // curr 是当前考虑元素的下标
        int p0 = 0, p2 = nums.size() -1;    // p0表示0的最右边界
        int cur = 0;                        // p2表示2的最左边界
        while (cur <= p2){
            if(nums[cur] == 0){
                swap(nums[cur++],nums[p0++]);
            }else if(nums[cur] == 2){
                swap(nums[cur], nums[p2--]);
            } else
                ++cur;
        }
    }
};