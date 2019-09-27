#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// 迭代方法
class SolutionI {
public:
    vector<string> expand(string S) {
        vector<string> ret = {""};
        int i = 0;
        while (i < S.size()){
            if(S[i] == '{'){
                i++;
                string cur = "";
                while (i < S.size() && S[i] !='}'){
                    cur += S[i++];
                    if (i < S.size() && S[i] == ',')
                        ++i;
                }
                sort(cur.begin(),cur.end());
                ++i;    // 跳过}
                int num = ret.size();   // 当前组合数
                vector<string> tmp;
                for(int k = 0; k < num;++k){
                    for (int j = 0; j < cur.size(); ++j) {
                        tmp.push_back(ret[k] + cur[j]);
                    }
                }
                ret = tmp;
            }
            else{
                int num = ret.size();
                vector<string> tmp;
                for(int k = 0; k < num;++k){
                    tmp.push_back(ret[k] + S[i]);
                }
                ++i;
                ret = tmp;
            }
        }
        return ret;
    }
};

// 回溯
class Solution {
    vector<string> ret;
public:
    vector<string> expand(string S) {
        dfs(S,0,S.size(),"");
        sort(ret.begin(), ret.end());
        return ret;
    }

private:
    void dfs(string &S, int i, int n, string str){
        if(i >= n){
            ret.push_back(str);
            return;
        }
        else{
            if(S[i]!= '{')
                dfs(S,i+1,n, str+S[i]);
            else{
                string cur;
                ++i;
                while(S[i]!='}'){
                    if(S[i]!=',')
                        cur.push_back(S[i]);
                    ++i;
                }
                ++i;
                for(char ch:cur)
                    dfs(S, i,n, str+ch);

            }
        }
    }
};

int main(){
    Solution sol;
    string s = "{a,b}c{d,e}f";
    vector<string> ret = sol.expand(s);
    for (auto str:ret)
        cout <<str << endl;
}