// 记录数组前缀和+暴力
// 时间复杂度O(n^2) 空间复杂度O(n)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty()) return 0;
        int minLen = INT_MAX, n = nums.size();
        vector<int> sums(n, 0);   // 前缀和数组
        sums[0] = nums[0];
        for(int i = 1; i < n; ++i)
            sums[i] = sums[i-1] + nums[i];

        for(int i = 0; i < n; ++i){
            for(int j = i; j <n; ++j){
                int sum = sums[j] - sums[i] + nums[i];
                if(sum >= s)
                    minLen = min(minLen, j - i +1);
            }
        }
        return minLen != INT_MAX ? minLen : 0;
    }
};


// 记录数组前缀和+二分查找
// 时间复杂度O(nlogn) 空间复杂度O(n)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums){
        int n = nums.size();
        if (n == 0)
            return 0;
        int ans = INT_MAX;
        vector<int> sums(n + 1, 0); //size = n+1 for easier calculations
        //sums[0]=0 : Meaning that it is the sum of first 0 elements
        //sums[1]=A[0] : Sum of first 1 elements
        //ans so on...
        for (int i = 1; i <= n; i++)
            sums[i] = sums[i - 1] + nums[i - 1];
        for (int i = 1; i <= n; i++) {
            int to_find = s + sums[i - 1];
            auto bound = lower_bound(sums.begin(), sums.end(), to_find);
            if (bound != sums.end()) {
                ans = min(ans, static_cast<int>(bound - (sums.begin() + i - 1)));
            }
        }
        return (ans != INT_MAX) ? ans : 0;
    }
};

// 双指针
// 时间复杂度O(n) 空间复杂度O(1)
// 用 2 个指针，一个指向数组开始的位置，一个指向数组最后的位置，
// 并维护区间内的和 sum 大于等于 s 同时数组长度最小。
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums){
        int n = nums.size();
        if (n == 0)
            return 0;
        int ans = INT_MAX;
        int left = 0, sum = 0;
        for(int i = 0; i < n; ++i){
            sum += nums[i];
            while (sum >= s){
                ans = min(ans, i+1 - left);
                sum -= nums[left++];
            }
        }
        return (ans != INT_MAX) ? ans : 0;
    }
};



