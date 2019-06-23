class Solution {
public:
    bool isValid(string s) {
        if(s.size() %2 == 1) return false;
        map<char,char> m;
        m['('] =')', m['['] = ']', m['{'] = '}';
        stack<char> st;
        for (auto ch:s){
            if(m.find(ch) != m.end())   // 左括号入栈
                st.push(ch);
            else if(st.empty()||m[st.top()]!= ch)   // 不匹配
                return false;
            else
                st.pop();               // 匹配
        }
        return st.empty();
    }
};