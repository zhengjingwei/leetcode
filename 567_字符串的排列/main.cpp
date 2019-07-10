#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        unordered_map<char, int> need;
        unordered_map<char, int> window;
        for(char c:s1)
            need[c] ++;
        int left = 0, right = 0;
        int match = 0;          // 匹配的字符数
        while (right<=s2.size()){
            char c1 = s2[right];
            if(need.count(c1)){
                window[c1] ++;
                if(window[c1] == need[c1])
                    match++;
            }
            right++;

            while (match == need.size()){
                if(right - left == s1.size())
                    return true;
                char c2 = s2[left];
                if(need.count(c2)){
                    window[c2]--;
                    if(window[c2] < need[c2])
                        match --;
                }
                left ++;
            }

        }

        return false;
    }
};

int main(){
    Solution sol;
    string s1 = "ab" ,s2 = "eidbaooo";
    cout<< sol.checkInclusion(s1,s2) <<endl;

    return 0;
}