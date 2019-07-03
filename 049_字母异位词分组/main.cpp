#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        for (string s:strs) {
            string key = s;
            sort(key.begin(),key.end());    // 排序后的字符串作为一组异位词的键值
            if(m.count(key) == 0)
                m[key] = {s};
            else
                m[key].push_back(s);
        }

        vector<vector<string>> ret;
        for(auto it = m.begin(); it!=m.end(); ++it)
            ret.push_back(it->second);
        return ret;
    }
};


int main(){
    vector<string> s = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution sol;
    vector<vector<string>> ret = sol.groupAnagrams(s);
    for (auto rows:ret){
        for(auto v:rows)
            cout << v <<" ";
        cout << endl;
    }
    return 0;
}

