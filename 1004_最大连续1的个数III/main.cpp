// 滑动窗口
// 时间复杂度：O(n) 空间复杂度：O(1)
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int l = 0, r = 0, ret = 0;
        int zeros = 0;
        while(r < A.size()){
            if(A[r] == 0)
                zeros++;
            // 当窗口内0的个数大于k时窗口缩小
            while(zeros > K){
                if(A[l++] == 0)
                    zeros--;
            }
            ret = max(ret, r-l+1);
            r++;
        }
        return ret;
    }
};