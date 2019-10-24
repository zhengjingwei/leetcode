// 滑动窗口
// 时间复杂度：O(n) 空间复杂度：O（1）
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> m;
        int l = 0, r = 0, ret = 0;
        int maxCount = 0;   // 出现次数最多的字符的出现次数
        while(r < s.size()){
            m[s[r]] ++;
            maxCount = max(maxCount, m[s[r]]);
            while(r - l +1  - maxCount > k) {   // 如果当前窗口长度-出现最多字符的次数>K，即不满足条件时
                m[s[l++]]--;    // 窗口向右缩小
                // 其实并不需要关心maxCount是否是被剔除的s[l]，因为这个循环内实际只会执行1次
            }
            ret = max(ret, r - l +1);
            r++;
        }
        return ret;
    }
};