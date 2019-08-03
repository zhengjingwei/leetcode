#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 给定一些标记了宽度和高度的信封，宽度和高度以整数对形式 (w, h) 出现。
 * 当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。
 * 请计算最多能有多少个信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。
 */



// 定义一个全局的比较函数对象
// 只需要重载()操作符就行
class cmp{
public:
    bool operator()(const vector<int>& a, const vector<int> &b) const {
        // 长度从小到大，长度相等的信封之间宽度从大到小排
        return a[0] != b[0] ? a[0] < b[0] : b[1] < a[1];
    }
};

/*
 * 最长递增子序列做法，时间复杂度o(nlogn)
 * （1）按照长度从小到大排，相同长度从大到小排
 * （2）信封最大层数等于排序完后宽度数组的最大递增子序列
 * 因为此时长度是递增的，并且相同长度是递减，保证如果宽度序列递增，必然满足长度和宽度都是递增
 */
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.empty() || envelopes[0].empty()) return 0;
        sort(envelopes.begin(), envelopes.end(), cmp());
        vector<int> dp;
        dp.push_back(envelopes[0][1]);  // 第一个元素

        for (int i = 1; i < envelopes.size(); ++i) {
            if (envelopes[i][1] > dp.back()){
                dp.push_back(envelopes[i][1]);
                continue;
            }

            int l = 0, r = dp.size();
            // 找到第一个大于等于该宽度的值，将其替换为该较小值
            while (l < r){
                int mid = (l+r) /2;
                if(envelopes[i][1] > dp[mid])
                    l = mid + 1;
                else
                    r = mid;
            }
            dp[l] = envelopes[i][1];
        }

        return dp.size();
    }
};

int main(){
    vector<vector<int>> nums = {{5,4},{6,4},{6,7},{2,3}};
    Solution sol;
    cout <<sol.maxEnvelopes(nums) << endl; // 3;  [2,3] => [5,4] => [6,7]
}

