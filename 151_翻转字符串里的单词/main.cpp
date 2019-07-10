class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        cleanSpace(s);
        int i = 0, j = 0, n = s.size();
        while (i < s.size()){
            // 跳过空格
            while (i <j || (i < n && s[i] == ' '))
                i++;    // 找到单词第一个字符位置
            while (j < i || (j < n && s[j]!= ' '))
                j++;    // 该单词后的空格位置
            reverse(s.begin()+i, s.begin()+j);
        }
        return s;
    }

private:
    void cleanSpace(string &s){
        int i = 0, j = 0, len = s.size();
        while (j < len){
            while (j < len && s[j] == ' ') j++;     // skip空格
            while (j < len && s[j] != ' ') s[i++] = s[j++]; // 复制非空格
            while (j < len && s[j] == ' ') j++;     // skip空格
            if(j < len) // 还有后续单词
                s[i++] = ' ';
        }
        s.erase(s.begin()+i, s.end());  // 删除尾部空格
    }
};