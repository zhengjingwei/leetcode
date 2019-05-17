#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {}

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (m.find(val) != m.end()) return false;
        nums.push_back(val);
        m[val] = nums.size() -1;    // 记录当前值在数组中位置
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (m.find(val) == m.end()) return false;
        // 把要删除元素与最末尾元素交换并通过pop_back删除
        int last = nums.back();
        m[last] = m[val];
        nums[m[last]] = last;
        nums.pop_back();
        m.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        if(nums.empty()) return -1;
        return nums[rand() % nums.size()];
    }

private:
    vector<int> nums;
    unordered_map<int,int> m;
};


int main(){

    return 0;
}

