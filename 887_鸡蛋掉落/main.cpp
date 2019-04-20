class Solution {
public:
    int superEggDrop(int K, int N) {
        int dp[N+1][K+1];   // dp[k][m]表示k个鸡蛋在m步内可以测出的最多的层
        memset(dp,0,sizeof(dp));
        for (int m = 1; m < N+1; ++m) {
            dp[m][0] = 0;   // 没有鸡蛋一层都测不出
            for (int k = 1; k < K+1; ++k) {
                dp[m][k] = dp[m - 1][k] + dp[m - 1][k - 1] + 1;
                if(dp[m][k] >= N)   // 如果能测到N层
                    return m;
            }
        }
        return N;
    }
};
