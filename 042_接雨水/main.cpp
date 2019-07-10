#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 暴力法
 * 对于数组中的每个元素，找到下雨后水能达到的最高位置
 * 等于两边最大高度的较小值减去当前高度的值
 *
 */

class SolutionI {
public:
    int trap(vector<int>& height) {
        int ret = 0;
        int len = height.size();
        for (int i = 1; i < len -1; ++i) {
            int maxLeft = height[i], maxRight = height[i];
            for (int j = i-1; j >=0 ; --j)
                maxLeft = max(maxLeft,height[j]);       // 找到左边最大值
            for (int j = i+1; j < len;++j)
                maxRight = max(maxRight,height[j]);     // 找到右边最大值
            ret += min(maxLeft,maxRight) - height[i];   // 两边最大高度的较小值减去当前高度的值
        }
        return ret;
    }
};

/*
 * 提前存储每个元素左边最大值和右边最大值
 * 时间复杂度O(N) 空间复杂度O(N)
 */
class SolutionII {
public:
    int trap(vector<int>& height) {
        if(height.size() < 3)
            return 0;
        int ret = 0;
        int len = height.size();
        vector<int> maxLeft(len,0), maxRgiht(len,0);
        maxLeft[0] = height[0], maxRgiht[len-1] = height[len-1];
        for (int i = 1; i < len; ++i)
            maxLeft[i] = max(maxLeft[i-1], height[i]);
        for (int i = len-2; i>=0 ; --i)
            maxRgiht[i] = max(maxRgiht[i+1], height[i]);
        for (int i = 0; i < len; ++i)
            ret += min(maxLeft[i], maxRgiht[i]) - height[i];
        return ret;
    }
};

/*
 * 双指针 一次遍历
 */
class SolutionIV {
public:
    int trap(vector<int>& height) {
        if(height.size() < 3)
            return 0;
        int ret = 0;
        int maxLeft = 0, maxRight = 0;
        int left = 0, right = height.size() -1;
        while(left < right){
            if (height[left] < height[right]){
                if (height[left] > maxLeft)
                    maxLeft = height[left];
                else
                    ret += maxLeft - height[left];
                ++ left;
            }else{
                if (height[right] > maxRight)
                    maxRight = height[right];
                else
                    ret += maxRight - height[right];
                -- right;
            }
        }

        return ret;
    }
};

class Solution {
public:
    int trap(vector<int>& height)
    {
        int ans = 0, current = 0;
        stack<int> st;
        while (current < height.size()) {
            while (!st.empty() && height[current] >= height[st.top()]) {
                int top = st.top();
                st.pop();
                if (st.empty())
                    break;
                int distance = 1;
                int bounded_height = min(height[current], height[st.top()]) - height[top];
                ans += distance * bounded_height;
            }
            st.push(current++);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {4,2,1,3};
//    vector<int> nums = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<sol.trap(nums)<<endl;
    return 0;
}