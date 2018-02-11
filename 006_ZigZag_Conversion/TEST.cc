#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows==1) return s;
		string str[numRows];
        int row = 0 ,flag=0;
        for(int i = 0;i<s.size();i++){
        	str[row] += s[i];
        	if(!flag&&row<numRows-1) 
				++row;
        	else if(row==numRows-1){
        		flag=1;
        		row--;
			}
			else if(flag && row>0) 
				row--;
			else if(row==0) {
				flag=0;
				++row;
			}
		}
		string ret;
		for(int i = 0;i<numRows;i++){
			ret +=str[i];
		}
		return ret;
    }
};

int main(int argc, char** argv) {
	string s = "AB";
	Solution sol;
	cout << sol.convert(s,1)<<endl;
	return 0;
}