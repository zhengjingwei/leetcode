#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m<1 || n < 1) return 0;
        if(m==1||n==1) return 1;

        vector<int> dp(n,0);
        dp[0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if(i == 0 && j == 0) continue;
                int up = 0, left = 0;
                if (i-1>=0) up = dp[j];
                if (j-1>=0) left = dp[j-1];
                dp[j] = left + up ;
            }
        }
        return dp.back();
    }
};

int main(){
    Solution sol;
    cout << sol.uniquePaths(3,2) << endl; // 3
    cout << sol.uniquePaths(7,3) << endl; // 28
    return 0;
}

