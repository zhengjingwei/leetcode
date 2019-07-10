#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 1 暴力法
 * 时间复杂度：假设 s 的长度是 n，words 里有 m 个单词，那么时间复杂度就是 O（n * m
 * 空间复杂度：O（m）
 */
class SolutionI {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> need;
        vector<int> ret;
        if(s.empty() || words.empty()) return ret;
        int wordNum = words.size(), wordLen = words[0].size();
        if (wordLen * wordNum > s.size()) return ret;
        // 统计word次数
        for(string s:words)
            need[s] ++;

        // 遍历所有子串 注意最后一个可能子串的起始坐标为s.size() - wordNum * wordLen
        for (int i = 0; i <= s.size() - wordNum * wordLen ; i++) {
            unordered_map<string, int> window;
            int cnt = 0;
            int begin = i;
            int match = 0;  // 匹配的词数目
            while (cnt < wordNum){
                string sub = s.substr(begin,wordLen);
                cnt ++;     // 当前子串的单词计数
                begin += wordLen;
                if(need.count(sub)){
                    window[sub] ++;
                    if(window[sub] == need[sub])
                        match ++;
                    else if(window[sub] > need[sub]){
                        match --;
                        break;
                    }
                } else
                    break;
            }

            if(match == need.size())
                ret.push_back(i);
        }

        return ret;
    }
};

/*
 * 滑动窗口
 * 时间复杂度O（m）
 * 空间复杂度O（n）
 */
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> need;
        vector<int> ret;
        if(s.empty() || words.empty()) return ret;
        int wordNum = words.size(), wordLen = words[0].size();
        int allLen = wordNum * wordLen;
        if (allLen > s.size()) return ret;
        // 统计word次数
        for(string s:words)
            need[s] ++;

        for (int i = 0; i < wordLen; ++i) {
            int cnt = 0;
            int left = i, right = i;
            unordered_map<string, int> window;
            while (right + wordLen <= s.size()){
                string lastWord = s.substr(right,wordLen);
                right += wordLen;
                window[lastWord] ++;
                cnt ++;
                while (window[lastWord] > need[lastWord]){
                    string firstWord = s.substr(left,wordLen);
                    left += wordLen;
                    window[firstWord] --;
                    cnt --;
                }
                if(cnt == wordNum)
                    ret.push_back(left);
            }
        }

        return ret;
    }
};

int main(){
//    string s = "barfoothefoobarman";
//    vector<string> word = {"foo","bar"};
    string s = "wordgoodgoodgoodbestword";
    cout<<s.size() << endl;
    vector<string> word = {"word","good","best","good"};
    Solution sol;
    vector<int> ret = sol.findSubstring(s,word);
    for (auto v:ret)
        cout << v <<" ";

    return 0;
}