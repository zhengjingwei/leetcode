### 

# [8. String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi/description/)

Implement `atoi` to convert a string to an integer.

**Hint:** Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

**Notes:** It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

 

**Requirements for atoi:**

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.



# 思路

这道题难度不高，主要是要理解题目的要求

题目的要求：

1. 首先需要丢弃字符串前面的空格；

2. 然后可能有正负号（注意只取一个，如果有多个正负号，那么说这个字符串是无法转换的，返回0。比如测试用例里就有个`“+-2”`）；

3. 字符串可以包含0~9以外的字符，如果遇到非数字字符，那么只取该字符之前的部分，如`“-00123a66”`返回为`“-123”`；

4. 如果超出`int`的范围，返回边界值（`2147483647`或`-2147483648`，INT_MAX和INT_MIN）。

5. 注意判断是否溢出的条件：

   ```C++
   if(ret >INT_MAX/10 || (ret == INT_MAX/10 && str[i]-'0' >7)
   ```

   其中一个测试用例就是

   ```
   Input:"2147483648"
   Expected:2147483647
   ```

# solution

```C++
class Solution {
public:
    int myAtoi(string str) {
    	int ret = 0,i=0;
		char sign = '+'; 	
    	while(str[i]==' ') ++i;
    	if(str[i]=='+'||str[i]== '-'){ // if string has sign
    		if((str[i]=='+'&&str[i+1]=='-') || (str[i]=='-'&&str[i+1]=='+')) // 2 sign
    		return 0;
    		sign = str[i]; // get the sign
    		++i;
		}
    	while(i < str.size()){
    		if(str[i]> '9' || str[i] <'0')
    			break;
    		if(ret >INT_MAX/10 || (ret == INT_MAX/10 && str[i]-'0' >7)){ // if overflow
    			if(sign =='+') return INT_MAX;
    			else if(sign = '-') return INT_MIN;
			}
			ret = ret * 10 + (str[i] -'0');
			++i;
		}
		if(sign == '-') ret = -ret;
		return ret;
    }
};
```

