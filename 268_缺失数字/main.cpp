class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ret = 0;
        for(int i = 0; i <= nums.size(); ++i)
            ret ^= i;
        for (int j = 0; j < nums.size(); ++j) 
            ret ^= nums[j];
        return ret;
    }
};