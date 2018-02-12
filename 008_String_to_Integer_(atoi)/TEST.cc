#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
    	if (x==0) return x;
        int sign = (x>0)?1:-1 ;
        int ret = 0;
        x = abs(x);
        while(x>0){
        	if(ret>INT_MAX/10) return 0;
        	ret = ret*10 +x%10;
        	x = x/10;
		}
		return sign * ret;
    }
};

int main(int argc, char** argv) {
	int ans = 1534236469;
	Solution sol;
	cout << sol.reverse(ans)<<endl;
	return 0;
}