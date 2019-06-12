#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 暴力
 * 时间复杂度O(n^2) 空间复杂度O(1)
 */
class SolutionI {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) return 0;
        int maxArea = 0;
        for (int i = 0; i < heights.size(); ++i) {
            int minHeight = heights[i];
            for (int j = i; j < heights.size() && heights[j]!=0; ++j){
                minHeight = min(minHeight, heights[j]);
                maxArea = max(maxArea,minHeight*(j-i+1));
            }
        }
        return maxArea;
    }
};

/*
 * 单调栈
 * 时间复杂度O(n) 空间复杂度O(n)
 */
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) return 0;
        stack<int> s;   // 存储序号
        s.push(-1);
        int maxArea = 0;
        for (int i = 0; i < heights.size(); ++i) {
            // 下降时pop
            while (s.top() != -1 && heights[s.top()] >= heights[i]){
                int tmp = s.top();
                s.pop();
                // 用弹出元素作为高形成的最大面积矩形，其宽是当前元素与s[top-1]之间的那些柱子
                maxArea = max(maxArea, heights[tmp] * (i-s.top() - 1));
            }
            s.push(i);
        }
        while (s.top()!= -1){
            int tmp = s.top();
            s.pop();
            int curArea = heights[tmp] * (heights.size() - s.top() - 1);
            maxArea = max(maxArea, curArea);v
        }

        return maxArea;
    }
};

int main(){
    vector<int > nums = {2,1,5,6,2,3};
    Solution sol;
    cout << sol.largestRectangleArea(nums) << endl;
    return 0;
}

