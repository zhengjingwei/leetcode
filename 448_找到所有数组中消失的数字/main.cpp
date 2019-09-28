class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ret;
        for(int i = 0; i < nums.size(); ++i){
            while(nums[i] != nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);  // nums[i]-1位置放置nums[i]元素
            }
        }
        for(int i = 0; i < nums.size(); ++ i)
            if(nums[i] != i+1)
                ret.push_back(i+1);             // 不匹配的即为未出现元素
        return ret;
    }
};