class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int end = A.size()-1;
        int even = 0, odd = 1; // 偶数坐标 奇数坐标
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