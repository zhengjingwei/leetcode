#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string validIPAddress(string IP) {
        if(isValidIPV4(IP)) return "IPv4";
        if(isValidIPV6(IP)) return "IPv6";
        return "Neither";
    }

private:
    void split(const string s, vector<string>& vs, const char delim=' '){
        istringstream iss(s);
        string tmp;
        while (getline(iss,tmp, delim)){
            vs.push_back(tmp);
        }
        if (!s.empty() && s.back() == delim) vs.push_back({});
        //加这句的原因是getline不会识别最后一个delim,避免误判"172.16.254.1.","2001:0db8:85a3:0:0:8A2E:0370:7334:"之类的情况
    }

    // 是否为有效IPV4地址
    bool isValidIPV4(string IP){
        vector<string> vs;
        split(IP, vs, '.');
        if(vs.size() != 4)
            return false;

        for (auto &v: vs) {
            if(v.empty() ||(v.size() > 1 && v[0] == '0') || v.size() > 3)
                return false;
            // 每个字符都是数字
            for(auto c:v){
                if(!isdigit(c))
                    return false;
            }
            int n = stoi(v);
            if(n<0 || n > 255)
                return false;
        }
        return true;
    }

    // 是否为有效IPV6地址
    bool isValidIPV6(string IP){
        vector<string> vs;
        split(IP, vs, ':');
        if(vs.size()!=8)
            return false;

        for (auto &v : vs) {
            if(v.empty() || v.size()>4) return false;
            for (auto c:v) {
                if(!(isdigit(c) || (c>='a' && c<='f') ||(c>='A' && c<='F')))
                    return false;
            }
        }
        return true;
    }
};

int main(){
    Solution sol;
    string s = "172.16.254.1";
    cout << sol.validIPAddress(s) << endl;
}