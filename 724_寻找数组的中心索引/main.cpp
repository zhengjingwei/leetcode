class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int curr = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if((sum - nums[i])%2 == 0){
                if(curr == (sum - nums[i])/2)
                    return i;
            }
            curr += nums[i];
        }
        return -1;
    }
};