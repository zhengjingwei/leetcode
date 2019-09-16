// 时间复杂度O(n^2) 空间复杂度O(1)
// 先排序，在给定区间通过双指针确定
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if(nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int ret = 0;
        for(int i = 0; i < nums.size(); ++i){
            int left = i+1;
            int right = nums.size() - 1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum >= target)
                    right --;               // 比target大right左移
                else{
                    ret += right - left;    // j=left, k=j+1..right的组合数
                    left ++;
                }
            }
        }
        return ret;
    }
};