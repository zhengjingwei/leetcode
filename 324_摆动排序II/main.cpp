#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Solution {
    // 时间复杂度O(n)，空间复杂度O(1)
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        std::nth_element(nums.begin(), nums.begin() + n/2, nums.end()); // O(n)
        int mid = nums[n/2];

        // 3-way-partion
        int i = 0;
        int j = 0;
        int k = n - 1;

        #define a(i) nums[(2*(i)+1)%(n|1)]

        while (j <= k) {
            if (a(j) > mid) {
                swap(a(i), a(j));
                ++i;
                ++j;
            } else if (a(j) < mid) {
                swap(a(j), a(k));
                --k;
            } else {
                ++j;
            }
        }
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1, 5, 1, 1, 6, 4};
    sol.wiggleSort(nums);
    for (auto c : nums)
        cout<<c<<" ";
    return 0;
}