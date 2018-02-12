# [13.Roman to Integer](https://leetcode.com/problems/roman-to-integer/description/)

Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.



# 思路

将输入罗马数字字符串转换为数字

## 罗马数字

罗马数字采用七个罗马字母作数字、即

I - 1
V - 5
X - 10
L - 50
C - 100
D - 500
M - 1000

记数的方法：

1. 相同的数字连写，所表示的数等于这些数字相加得到的数，如 Ⅲ=3；
2. 小的数字在大的数字的右边，所表示的数等于这些数字相加得到的数，如 Ⅷ=8、Ⅻ=12；
3. 小的数字（限于 Ⅰ、X 和 C）在大的数字的左边，所表示的数等于大数减小数得到的数，如 Ⅳ=4、Ⅸ=9；




使用unordered_map存储罗马数字和阿拉伯数字的kv对，然后遍历字符串进行统计和处理。

# solution

```c++
class Solution {
public:
    int romanToInt(string s) {
		unordered_map<char, int> T = { { 'I' , 1 },
	                                   { 'V' , 5 },
	                                   { 'X' , 10 },
	                                   { 'L' , 50 },
	                                   { 'C' , 100 },
	                                   { 'D' , 500 },
	                                   { 'M' , 1000 } };
	    int num = T[s[0]] ; 
    	for( int i=1 ;i<s.size();i++){
    		if(T[s[i]] > T[s[i-1]]) 
    			num += T[s[i]] - 2*T[s[i-1]] ;
    		else 
    			num += T[s[i]];
		}
		return num;
    }
};
```

