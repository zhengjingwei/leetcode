#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int rev = 0, num = x;
        while(num > 0){
            rev = rev *10 + num%10;
            num= num/10;
        }
        if(rev == x) 
            return true;
        else 
            return false;
    }
};

int main(int argc, char** argv) {
    int x = -2147447412;
    Solution sol;
    cout << sol.isPalindrome(x) <<endl;
    return 0;
}