// 滑动窗口
// 时间复杂度：O(n) 空间复杂度：O(n)
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> m;
        int cnt = 0;    // 不同字符个数
        int left = 0, right = 0;
        int maxLen = 0;
        while(right < s.size()){
            if(m[s[right]] == 0)
                cnt ++;
            m[s[right++]]++;
            while(cnt > 2){
                m[s[left]]--;
                if(m[s[left++]] == 0){
                    cnt --;
                }
            }
            maxLen = max(maxLen, right - left); // right指向的是下一个字符
        }
        return maxLen;
    }
};