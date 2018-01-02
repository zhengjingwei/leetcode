# 3.Longest Substring Without Repeating Characters

Given a string, find the length of the **longest substring** without repeating characters.

**Examples:**

Given `"abcabcbb"`, the answer is `"abc"`, which the length is 3.

Given `"bbbbb"`, the answer is `"b"`, with the length of 1.

Given `"pwwkew"`, the answer is `"wke"`, with the length of 3. Note that the answer must be a **substring**, `"pwke"`is a *subsequence* and not a substring.



------

没有重复字符的最长子串

使用map来存储字符串以及对应的索引，建立一张索引表。以起点`start`开始查找，若无重复字符，则`maxlen = i-start`

```
abcabcbb
^  ^
s  i
```

当字符查表已存在，更新起点`start`为当前字符索引

## Solution

```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> char_map;
        int maxlen= 0;
        int start = -1;
        for(int i = 0; i<s.length();i++){
            if(char_map.count(s[i])!=0){
                start = max(start,char_map[s[i]]);
            }
            char_map[s[i]]=i;
            maxlen = max(maxlen,i-start);
        }
        return maxlen;
    }
};
```



