class Solution {
public:
    bool isPowerOfThree(int n) {
        while (n > 1 ){
            if(n % 3 == 0)
                n /= 3;
            else
                return false;
        }
        return n == 1;
    }
};