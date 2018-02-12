#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string M[] = {"","M","MM","MMM"};
        string C[] = {"","C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return  M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
    }
};

int main(int argc, char** argv) {
    int x = 2;
    Solution sol;
    cout << sol.intToRoman(x)<<endl;
    return 0;
}