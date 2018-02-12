### 

# [7. Reverse Integer](https://leetcode.com/problems/reverse-integer/description/)

Given a 32-bit signed integer, reverse digits of an integer.

**Example 1:**

```
Input: 123
Output:  321
```

**Example 2:**

```
Input: -123
Output: -321
```

**Example 3:**

```
Input: 120
Output: 21
```

**Note:**
Assume we are dealing with an environment which could only hold integers within the 32-bit signed integer range. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

# 思路

注意一点就是乘10的时候可能溢出，需要进行判断乘10之前是否已经大于 `INT_MAX/10`。

INT_MAX = 2147483647 = 2^31 -1 = 1<<31 -1

# solution

```C++
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
```

