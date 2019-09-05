// 等价于在长度为m*n的数组中进行二分查找 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0) return false;
        int n = matrix[0].size();
        int left = 0, right = m * n -1;
        while(left <= right){
            int mid = (left + right) /2;
            if(target == matrix[mid / n][mid % n])
                return true;
            else if(target < matrix[mid / n][mid % n])
                right = mid - 1;
            else 
                left = mid + 1;
        }
        return false;
    }
};