// 滑动窗口+双指针
// 相当于统计不同整数个数为k 的子数组的数量
// 时间复杂度：O(n) 空间复杂度：O(K))
// 需要建立两个窗口，其中w1是以r为结尾的最长满足的窗口；w2是以r为结尾的最短满足的窗口
// 则(l1,r) (l2,r)即为之间的区间都是满足的窗口
// 注意：一个窗口是无法做到的，因为所求的不是最长/最短，双指针移动的方向不定
class Window{
public:
    unordered_map<int,int> counter; // 数字出现次数统计
    int unique = 0;                 // 不重复数字个数
    // 窗口增加一个数字
    void add(int x){
        counter[x] ++;
        if(counter[x] == 1)
            unique++;
    }
    // 窗口减少一个数字
    void remove(int x){
        counter[x] --;
        if(counter[x]==0)
            unique--;
    }
};
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int l1 = 0,l2 = 0, r = 0;  
        int ret = 0;
        Window w1, w2;
        while(r < A.size()){
            w1.add(A[r]);
            w2.add(A[r]);
            while(w1.unique > K){
                w1.remove(A[l1++]);
            }
            while(w2.unique >= K){
                w2.remove(A[l2++]);
            }
            ret += l2 - l1; // 中间有l2-l1个满足要求的窗口
            r++;
        }
        return ret;
    }
};