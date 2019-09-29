class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(), s.end());    // 反转字符串
        int i = 0;
        while(s[i]==' ')    
            ++i;                        // 清除末尾的空格
        if(i == s.size()) return 0;
        int begin = i;                  // 开始字符
        while(i < s.size() && s[i]!=' ')    // 记录第一个空格位置
            ++i;
        return i-begin;
    }
};