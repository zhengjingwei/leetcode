// 单元素蓄水池抽样
class Solution {
    vector<int> nums;
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
        srand(time(NULL));
    }
    
    int pick(int target) {
        int cnt = 0;
        int ret = -1;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == target){
                cnt ++;
                if(rand() % cnt == 0)
                    ret = i;
            }
        }
        
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */