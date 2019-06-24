class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() -2;
        while(i>= 0 && nums[i+1] <= nums[i])    // 从右往左找到第一个nums[i]>nums[i+1]
            --i;
        if(i>=0){
            int j = nums.size() -1;
            while(j>=0 && nums[j]<=nums[i])
                --j;
            swap(nums[i],nums[j]);              // 交换
        }
        reverse(nums.begin()+i+1, nums.end());  // 反转nums[i]后部分
    }
};