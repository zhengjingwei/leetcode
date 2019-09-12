// 时间复杂度O(n) 空间复杂度O(n)
class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int n = A.size();
        vector<int> sums(n+1);  // 前缀和数组
        for (int i = 0; i < n; ++i) {
            sums[i+1] = sums[i] + A[i];
        }

        int ret = n+1;
        deque<int> dq;  //
        // 需要找到x,y使得sums[y]-sums[x] >= K并且y-x最小
        // 单调双端队列，存储对于固定的y，设opt(y)为最大的满足sums[x] <= sums[y] - k的x
        for (int y = 0; y < sums.size(); ++y) {
            while (!dq.empty() && sums[y] <= sums[dq.back()])
                dq.pop_back();
            while (!dq.empty() && sums[y] >= sums[dq.front()] + K){ // 满足y-x>=k
                ret = min(ret, y - dq.front()); // 需要弹出，因为如果y2>y1,并且opt(y2)=opt(y1)=x,则y2-x必然大于y1-x
                dq.pop_front();                 // 不会作为所有 y - opt(y) 中的最小值
            }
            dq.push_back(y);
        }

        return ret < n+1 ? ret : -1;
    }
};