class NumArray {
    vector<int> sums;   // sums[i]表示前i项和
public:
    NumArray(vector<int>& nums) {
        int sum = 0;
        sums.push_back(sum);    // 前0项和为0
        for(int i = 0; i < nums.size(); ++i){
            sum+= nums[i];
            sums.push_back(sum);
        }
    }
    
    int sumRange(int i, int j) {
        return sums[j+1] - sums[i]; // 注意前j项和为sums[j+1]
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */