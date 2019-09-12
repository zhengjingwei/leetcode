// 贪心+哈夫曼编码
// 时间复杂度O(nlongn) 空间复杂度O(n)
class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        multiset<int, less<int>> m; // 最小堆
        for(int n:sticks)
            m.insert(n);
        int ret = 0;
        while(m.size()>1){
            int a = *m.begin();m.erase(m.begin());   // 取出当前最小的两个数
            int b = *m.begin();m.erase(m.begin());
            ret += a + b;
            m.insert(a+b);
        }
        return ret;
    }
};