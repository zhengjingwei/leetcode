# [Palindrome Number](https://leetcode.com/problems/palindrome-number/description/)

Determine whether an integer is a palindrome. Do this without extra space.



# 思路

题目要求不能使用额外的空间，所以不能转成字符串来处理。解题思路很简单，将比较原来的数和倒置后的数是否为同一个数即可。

注意:

- 负数不是回文数
- 在倒置过程中不需要判断是否溢出，因为逆序后溢出的数必然和原来的数不同，肯定不是回文数



# solution

```C++
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
```

