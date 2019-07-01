class Solution {
public:
    int mySqrt(int x) {
        long long i = 0;
        while(i*i <= x )
            ++i;
        return i-1;
    }
};

class Solution {
public:
    int mySqrt(int x) {
        long begin = 0, end = x;
        
        while(begin < end){
            long mid = (begin + end) /2;
            if(mid * mid == x)
                return mid;
            else if (mid * mid < x)
                begin = mid + 1;
            else
                end = mid -1;
        }
        return (begin * begin <= x)? begin:begin -1;
    }
};
