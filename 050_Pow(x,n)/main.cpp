class Solution {
public:
    double myPow(double x, int n) {
        double eposilon = 1e-9;
        if(fabs(x) < eposilon) return 0.0;
        if(fabs(x - 1.0) < eposilon) return 1.0;
        if(n == 0) return 1;
        long N = n;
        N = N < 0 ? -N:N;
        return n < 0 ? 1.0 / (powCore(x,N)): powCore(x,N) ;
    }

private:
    double powCore(double x, long n){
        if(n==0) return 1;
        double ret = powCore(x, n/2);
        ret *= ret;
        if(n%2)
            ret *= x;
        return ret;
    }
};