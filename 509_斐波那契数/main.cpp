class Solution {
public:
    int fib(int N) {
        if(N == 0 || N== 1)
            return N;
        int fnminus2 = 0, fnminus1 = 1;
        int ret = 0;
        for (int i = 2; i<=N; ++i ){
            ret = fnminus2 + fnminus1;
            fnminus2 = fnminus1;
            fnminus1 = ret;
        }
        
        return ret;
    }
};