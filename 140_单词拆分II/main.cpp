class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,vector<string>> m;
        vector<string> ret;
        ret = wordBreakCore(s,wordDict,m);
        return ret;
    }


    // 得到字符串s的字典拆分组合
    vector<string> wordBreakCore(string s, vector<string>& wordDict, unordered_map<string,vector<string>> &m){
        if(m.count(s)) return m[s];     // 如果字典里有直接返回已有组合
        if(s.empty()) return {""};      // 返回空串

        vector<string> result;
        // 匹配词典
        for (string word:wordDict) {
            if(s.substr(0,word.size()) == word){
                vector<string> res = wordBreakCore(s.substr(word.size()), wordDict, m);
                for(string str:res){
                    // res列表里每个字符串前加入word +  " "
                    result.push_back(word + (str.empty()?"": " "+ str));
                }
            }
        }
        m[s] = result;
        return result;
    }
};