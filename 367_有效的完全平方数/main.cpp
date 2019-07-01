class Solution {
public:
    int isPerfectSquare(int x) {
        long begin = 0, end = x;
        
        while(begin < end){
            long mid = (begin + end) /2;
            if(mid * mid == x)
                return true;
            else if (mid * mid < x)
                begin = mid + 1;
            else
                end = mid -1;
        }
        return (begin * begin == x)? true:false;
    }
};