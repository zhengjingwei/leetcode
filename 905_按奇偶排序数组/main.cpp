// 时间复杂度O(n)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int end = A.size()-1;
        int even = 0, odd = 1; // 将要调整的偶数坐标和奇数坐标
        while(even <= end && odd <= end){
            if(A[end] & 1){
                swap(A[end], A[odd]);
                odd += 2;
            }else{
                swap(A[end], A[even]);
                even += 2;
            }
        } 
        return A;
    }
};