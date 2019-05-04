#include <iostream>
#include <bits/stdc++.h>
using namespace std;


//class Solution {
//public:
//    vector<int> topKFrequent(vector<int>& nums, int k) {
//        unordered_map<int, int> count;
//        for (auto num:nums)
//            ++count[num];
//        multimap<int, int, greater<int>> m;
//        for (auto f:count)
//            m.insert(make_pair(f.second, f.first));
//
//        vector<int> ret;
//        for(auto it = m.begin();it!=m.end() && k; ++ it,--k)
//            ret.push_back(it->second);
//        return ret;
//    }
//};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        using E = std::pair<int, int>;
        priority_queue<E, vector<E>, greater<E>> minHeap;   // 求topK大用小根堆
        map<int, int> count;

        for(auto e: nums)
            ++count[e];

        for (auto x:count) {
            auto p = make_pair(x.second, x.first);
            if(minHeap.size() == k){
                if(p < minHeap.top()) continue;
                minHeap.pop();
            }
            minHeap.push(p);
        }

        vector<int> ret(k);
        while (!minHeap.empty()){
            ret[--k] = minHeap.top().second;
            minHeap.pop();
        }
        return ret;
    }
};

int main(){
    vector<int> m = {3,0,1,0};

    Solution sol;
    vector<int> ret = sol.topKFrequent(m,1);
    return 0;
}

