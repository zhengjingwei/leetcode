#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        if (buildings.empty()) return {};
        multiset<pair<int, int>> st;    // 存储自动排序
        // 将矩形左右端点加入
        for (auto b : buildings){
            st.insert(make_pair(b[0],-b[2]));
            st.insert(make_pair(b[1],b[2]));
        }

        vector<vector<int>> ret;
        multiset<int> height = {0};
        int m = 0;
        // 从左往右扫描
        for (auto s:st){
            if (s.second < 0) height.insert(-s.second); // 矩形左端点，加入对应高度
            else height.erase(height.find(s.second));   // 矩形右端点，删除对应高度
            if (m != *height.rbegin())  // 出现关键点
                ret.push_back({s.first, *height.rbegin()});
            m = *height.rbegin();
        }

        return ret;
    }
};

int main(){
    vector<vector<int>> r = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
    Solution sol;
    vector<vector<int>> ret = sol.getSkyline(r);
    return 0;
}