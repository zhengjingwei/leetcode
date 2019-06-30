class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty()) return false;
        if(nums.size() == 1) return true;

        int last = nums.size() -1 ; // 上一个可以到达终点并且最左的位置

        for (int i = nums.size()-2; i >=0 ; --i) {
            if(i+nums[i] >= last)
                last = i;
        }
        return last==0;
    }
};