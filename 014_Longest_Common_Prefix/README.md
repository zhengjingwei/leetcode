# [4.Longgest Common Prefix](https://leetcode.com/problems/longest-common-prefix/description/)

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string `""`.

**Example 1:**

```
Input: ["flower","flow","flight"]
Output: "fl"
```

**Example 2:**

```
Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
```



# 思路

顺序遍历




# solution

```c++
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        if(strs.size()==1) return strs[0];
        int min_len = strs[0].length();
        string prefix = "";
        for(int i =0; i < min_len; i++){		
        	for(int j=0; j < strs.size(); j++){
        		if (strs[0][i] != strs[j][i])
        			return prefix;
        		if (strs[j].size()<min_len)
					min_len = strs[j].size();       		
			}
			prefix += strs[0][i];
		}
		return prefix;
    }
};
```

