class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()<=1) return nums.size();
        int i = 0; // 慢指针
        for(int j = 1; j < nums.size() ; j ++){ // 快指针
            if(nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j]; // 复制值
            }
        }
        return i+1;
    }
};