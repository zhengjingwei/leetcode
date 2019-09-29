// 只有一个字符出现奇数次，其余出现偶数次
class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> m;
        for(char c:s)
            m[c]+=1;
        int odd = 0;
        for(auto it = m.begin(); it!=m.end();++it)
            if(it->second % 2 == 1)
                odd ++;
        return (odd == 0) || (odd == 1);
    }
};