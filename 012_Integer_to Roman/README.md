# [Integer to Roman](https://leetcode.com/problems/integer-to-roman/description/)

Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.



# 思路

将输入整数转换为罗马数字

## 罗马数字

罗马数字采用七个罗马字母作数字、即Ⅰ（1）、X（10）、C（100）、M（1000）、V（5）、L（50）、D（500）。记数的方法：

1. 相同的数字连写，所表示的数等于这些数字相加得到的数，如 Ⅲ=3；
2. 小的数字在大的数字的右边，所表示的数等于这些数字相加得到的数，如 Ⅷ=8、Ⅻ=12；
3. 小的数字（限于 Ⅰ、X 和 C）在大的数字的左边，所表示的数等于大数减小数得到的数，如 Ⅳ=4、Ⅸ=9；



某一位上数字表示的规律：

1：直接表示

2、3：小数叠加

4：5-1

5：直接表示

6：5+1

7：5+2

8：5+3

9：10-1

10：直接表示



# solution

自己写的，比较长

```C++
class Solution {
public:
    string intToRoman(int num) {
        string str;
        while(num>= 1000){
        	num -=1000;
        	str += 'M';
		}
		int hun = (num%1000)/100;
		switch(hun){
			case 0:break;
			case 1:str+="C";break;
			case 2:str+="CC";break;
			case 3:str+="CCC";break;
			case 4:str+="CD";break;
			case 5:str+="D";break;
			case 6:str+="DC";break;
			case 7:str+="DCC";break;
			case 8:str+="DCCC";break;
			case 9:str+="CM";break;
		}
		int dec = (num%100)/10;
		switch(dec){
			case 0:break;
			case 1:str+="X";break;
			case 2:str+="XX";break;
			case 3:str+="XXX";break;
			case 4:str+="XL";break;
			case 5:str+="L";break;
			case 6:str+="LX";break;
			case 7:str+="LXX";break;
			case 8:str+="LXXX";break;
			case 9:str+="XC";break;
		}
		int unit = num%10 ;
		switch(unit){
			case 0:break;
			case 1:str+="I";break;
			case 2:str+="II";break;
			case 3:str+="III";break;
			case 4:str+="IV";break;
			case 5:str+="V";break;
			case 6:str+="VI";break;
			case 7:str+="VII";break;
			case 8:str+="VIII";break;
			case 9:str+="IX";break;			
		}
		return str ;
    }
};
```



参考网上精简的代码

```C++
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
```

