// 找到第一个大于等于target的位置
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        int begin = 0, end = nums.size();
        while(begin < end){
            int mid = (begin + end) /2;
            if (nums[mid] < target)
                begin = mid + 1;
            else
                end = mid;
        }
        return begin;
    }
};