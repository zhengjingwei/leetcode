// 遍历字符串，用栈存储访问的子目录，便于../返回上一目录
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int i = 0;
        // 遍历字符串 将目录存入栈
        while(i < path.size()){
            while(i < path.size() && path[i] == '/') ++i;   // 跳过连续的/
            if(i == path.size())
                break;
            string tmp = "";
            while(i < path.size() && path[i]!='/')
                tmp += path[i++];
            if(tmp == ".."){
                if(!st.empty())
                    st.pop();   // 弹栈
            }else if(tmp != ".")
                st.push(tmp);
        }
        string ret = "";
        if(st.empty())
            return "/";     // 当路径表示的是根目录时 栈为空
        while(!st.empty()){
            ret = "/" + st.top() + ret;
            st.pop();
        }
        return ret;
    }
};