#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 完全平方数-动态规划
 * 时间复杂度O(N^(3/2)) 空间复杂度O(N)
 */
class Solution {
public:
    int numSquares(int n) {
        if(n <= 0) return 0;
        if(isSquare(n)) return 1;

        vector<int> dp(n+1, 0);

        for (int i = 1; i <=n ; ++i) {  // 注意对完全平方数的定义从1开始
            if(isSquare(i)){
                dp[i] = 1;  // 完全平方数
                continue;
            }
            int tmp = int(sqrt(i));
            int minCount = n;
            // 在比i小的数中寻找最少组合
            for (int j = 1 ; j*j < i ; ++j) {
                minCount = min(minCount,dp[j*j] + dp[i - j*j]);
            }
            dp[i] = minCount;
        }
        return dp[n];
    }

private:
    // 判断是否为完全平方数
    bool isSquare(int n){
        int tmp = int(sqrt(n));
        return n == tmp * tmp;
    }
};


/*
 * 拉普拉斯四平方数和公式
 */
class SolutionI {
public:
    int numSquares(int n) {
        //先根据上面提到的公式来缩小n
        while(n % 4 == 0) {
            n /= 4;
        }
        //如果满足公式 则返回4
        if(n % 8 == 7) {
            return 4;
        }
        //在判断缩小后的数是否可以由一个数的平方或者两个数平方的和组成
        int a = 0;
        while ((a * a) <= n) {
            int b = sqrt((n - a * a));
            if(a * a + b * b == n) {
                //如果可以 在这里返回
                if(a != 0 && b != 0) {
                    return 2;
                } else{
                    return 1;
                }
            }
            a++;
        }
        //如果不行 返回3
        return 3;
    }
};

int main(){
    int n = 2115;   // 3
    Solution sol;
    cout << sol.numSquares(n) << endl;
    return 0;
}

