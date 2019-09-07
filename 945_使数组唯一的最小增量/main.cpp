// 时间复杂度O(nlogn) 空间复杂度O(1)
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if(A.size()<2) return 0;
        sort(A.begin(), A.end());
        int last = A[0], ret = 0;
        for(int i = 1; i < A.size(); ++i){
            if(A[i] <= last){
                ret += last - A[i] +1;  // 将A[i]调整为last+1所需次数
                last ++;
            }
            else
                last = A[i];
        }
        return ret;
    }
};