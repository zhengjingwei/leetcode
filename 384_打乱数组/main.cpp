#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * Knuth-Durstenfeld Shuffle
 * 随机产生[0,k]位置随机数，与位置k元素交换；每次产生一个随机数放队列末尾
 * 原地打乱算法 时间复杂度O(n)
 */
class Solution {
    vector<int> origin;
public:
    Solution(vector<int>& nums) {
        origin = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return origin;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> arr(origin);
        for (int i = arr.size() -1; i >=0 ; --i) {
            swap(arr[rand()%(i+1)], arr[i]);
        }
        return arr;
    }
};

/*
 * Inside-Out Algorithm
 * 从前向后扫描数据，把位置i的数据随机插入到前i个（包括第i个）位置中（假设为k）
 * 时间复杂度O(n) 空间复杂度O(n)
 */
//class Solution {
//    vector<int> origin;
//public:
//    Solution(vector<int>& nums) {
//        origin = nums;
//    }
//
//    /** Resets the array to its original configuration and return it. */
//    vector<int> reset() {
//        return origin;
//    }
//
//    /** Returns a random shuffling of the array. */
//    vector<int> shuffle() {
//        vector<int> arr(origin);
//        for (int i = 0; i <arr.size() ; ++i) {
//            swap(arr[rand()%(i+1)], arr[i]);
//        }
//        return arr;
//    }
//};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */


int main(){

    vector<int> nums = {1,2,3,4,5,6};
    Solution *obj = new Solution(nums);
    vector<int> p1 = obj->shuffle();
    vector<int> p2 = obj->reset();

    return 0;
}

