/*1. 以较大的数组作为set用来查询；num1较小，num2较大
2. 排序nums1；为了去重
3. 遍历nums1进行查询

时间复杂度：设较大的数组长度m，较小数组长度n
则排序时间O（nlogn），查询O（n），总时间O（n）
空间复杂度：O（m）

进一步，可以将两个数组都进行排序，在大数组中进行二分查找
        时间复杂度：O（mlogm）
空间复杂度：O（1）*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        if(nums1.empty() || nums2.empty())
            return ret;

        if(nums1.size() > nums2.size())
            swap(nums1, nums2);

        sort(nums1.begin(), nums1.end());
        unordered_set<int> s(nums2.begin(), nums2.end());
        int i = 0;
        while(i < nums1.size()){
            while(i < nums1.size()-1 && nums1[i] == nums1[i+1])
                ++i;
            if(s.count(nums1[i]))
                ret.push_back(nums1[i]);
            ++i;
        }
        return ret;
    }
};