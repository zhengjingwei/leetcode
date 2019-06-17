#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0? !(n&(n-1)): false;
    }
};


int main(){
    Solution sol;
    cout<< sol.isPowerOfTwo(16)<<endl;
    return 0;
}