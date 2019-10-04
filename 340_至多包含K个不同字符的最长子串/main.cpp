/*
 * 滑动窗口+哈希表
 * 时间复杂度O(n) 空间复杂度O(k)
 */
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(s.size() == 0 || k <= 0)
            return 0;
        unordered_map<char, int > m;
        int l = 0, r = 0;   // 滑动窗口左右指针
        int maxLen = 1;     // 最大长度
        int count = 0;
        while(r < s.size()){
            if (m[s[r]] == 0)
                count ++;
            m[s[r]] += 1;
            r++;
            // 左指针移动减小
            while (count > k){
                if(m[s[l]] == 1)
                    count--;
                m[s[l]] -= 1;
                l++;
            }
            maxLen = max(maxLen, r - l);
        }
        return maxLen;
    }
};