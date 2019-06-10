#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 动态规划
 * 以i为根节点，设左子树节点数为j(0<=j<=n-1)，右子树节点数为i-1-j
 * dp[n] = sum(dp[i]*d[n-1-i])  等于左右子树的组合
 * 时间复杂度O(n^2) 空间复杂度O(n)
 */
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 1, dp[1] = 1;
        for(int i = 2; i<= n; ++i)
            for (int j = 0; j <= i-1; ++j)
                dp[i] += (dp[j] * dp[i-1-j]);
        return dp[n];
    }
};

int main(){
    Solution sol;
    cout << sol.numTrees(1) << endl;
    cout << sol.numTrees(2) << endl;
    cout << sol.numTrees(3) << endl;
    cout << sol.numTrees(4) << endl;
    cout << sol.numTrees(5) << endl;
    return 0;
}

