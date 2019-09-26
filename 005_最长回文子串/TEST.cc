#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() <= 1) return s;
        int id=0,mx=0;
        // Manacher Algorithm
        string str = preProcess(s);
        int len = str.size();
        vector<int> p(len,0);
        for(int i =1; i< len-1;i++){
        	p[i] = mx > i ? min(p[2*id -i],mx-i):1; //mx为当前最长回文子串的右边界
        	while(str[i+p[i]] == str[i-p[i]]) // 计算P[i] 
        		p[i]++;
        	if( i + p[i] > mx){
        		mx = i+ p[i];
        		id = i;
			}
		}
		// 遍历p，寻找最大回文长度 
		int maxlen =0,index =0;
		for(int i =1;i<len-1;i++){
			if(p[i] > maxlen){
				maxlen = p[i];
				index = i;
			}
		}
		return s.substr((index - maxlen)/2,maxlen-1);	//p[i]-1为原字符串中的回文子串长度 
	}
	string preProcess(string &s){
		int n = s.size();
		string res;
		res.push_back('$');
		res.push_back('#');
		for(int i = 0; i<n ;i++){
			res.push_back(s[i]);
			res.push_back('#');
		}
		res.push_back('^');
		return res;
	}
};

int main(int argc, char** argv) {
	string s = "bb";
	Solution sol;
	cout << sol.longestPalindrome(s)<<endl;
	return 0;
}