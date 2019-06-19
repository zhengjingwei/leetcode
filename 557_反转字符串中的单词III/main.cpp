class Solution {
public:
    string reverseWords(string s) {
        if(s.empty()) return s;
        string::iterator wordBegin = s.begin(); // 指向单词的起始位置
        for (string::iterator it = s.begin(); it!=s.end() ; ++it) {
            if(*it == ' '){
                reverse(wordBegin,it);  // 翻转单词
                wordBegin = it+1;
            }
        }
        if(*(s.end()-1)!=' ') reverse(wordBegin,s.end());
        return s;
    }
};
