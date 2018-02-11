### 

# [6. ZigZag Conversion](https://leetcode.com/problems/zigzag-conversion/description/)

The string `"PAYPALISHIRING"` is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

```
P   A   H   N
A P L S I I G
Y   I   R
```

And then read line by line: 

```
"PAHNAPLSIIGYIR"
```

Write the code that will take a string and make this conversion given a number of rows:

```
string convert(string text, int nRows);
```

```
convert("PAYPALISHIRING", 3)
```

 should return 

```
"PAHNAPLSIIGYIR"
```



# 思路

就是把字符串原顺序012345……按下图所示排列：

![img](http://img.blog.csdn.net/20141026161841654?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvbGppYWJpbg==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/Center)

比较直观的解法是，用一个字符串数组 string[rows] 来存储每一行，最后一拼接就是最终结果。

用一个flag表示正向还是反向，即上图中从第一行到最后一行还是最后一行到第一行。

# solution

```C++
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
```

