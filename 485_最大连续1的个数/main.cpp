class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ret = 0;
        int cnt = 0;;
        for(auto num : nums){
            if(num == 1){
                cnt ++;
                ret = max(ret, cnt);
            }else
                cnt = 0;
        }
        return ret;
    }
};