#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        int currentLen = 0, maxLen = 0;
        map<char, int> pos;


        for(int i = 0; i< s.size(); ++i){
            int preIndex = pos.count(s[i]) == 0? -1: pos[s[i]];
            if(i == 0 || i-preIndex > currentLen)
                currentLen++;
            else
                currentLen = i-preIndex;

            pos[s[i]] = i;
            maxLen = currentLen>maxLen? currentLen: maxLen;
        }

        return maxLen;
    }
};

int main(){
    string s = "hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    Solution sol;
    cout << sol.lengthOfLongestSubstring(s) << endl;
    return 0;
}

