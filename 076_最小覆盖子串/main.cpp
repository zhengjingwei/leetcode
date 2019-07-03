#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 暴力解法
 * 超时
 */
class SolutionI {
public:
    string minWindow(string s, string t) {
        int minLen = INT_MAX;
        string ret;
        sort(t.begin(), t.end());
        if(s==t) return s;
        if(s.size() < t.size()) return ret;
        for (int i = 0; i <= s.size() - t.size(); ++i) {
            for (int j = i+t.size()-1; j < s.size(); ++j) {
                string sub = s.substr(i,j-i+1);
                int cnt = 0;
                sort(sub.begin(),sub.end());
                for (int k = 0; k < sub.size() && cnt < t.size(); ++k) {
                    if(sub[k] == t[cnt])
                        cnt ++;
                }
                if(cnt == t.size()){
                    if(sub.size() < minLen){
                        minLen = sub.size();
                        ret = s.substr(i,j-i+1);
                    }
                }
            }
        }
        return ret;
    }
};

/*
 * 滑动窗口-双指针法
 * left指针收缩窗口；right指针扩大窗口
 * 先找到一个可行窗口，再不断收缩
 * 时间复杂度O(|S|+|T|) 空间复杂度O(|S|+|T|)
 */
class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty())
            return "";
        string ret;
        unordered_map<int, int> require; // 建立字典对t的字符进行计数
        unordered_map<int, int> window;
        for(char c:t)
            require[c] ++;

        int left = 0, right = 0;    // 双指针
        int match = 0;              // 记录window中已经有多少字符符合要求了
        int minLen = INT_MAX;
        int begin = 0;              // 最小子串的起始点

        while (right < s.size()){
            // 右指针右移加入字符扩大窗口
            char c1 = s[right];
            if(require.count(c1)){
                window[c1] ++;
                if(window[c1] == require[c1])
                    match ++;
            }
            right ++;

            // 左指针右移缩小窗口
            while (match == require.size()){
                if (right - left < minLen){
                    begin = left;
                    minLen = right - left;
                }
                char c2 = s[left];
                if(require.count(c2)){
                    window[c2] --;
                    if(window[c2] < require[c2])
                        match--;
                }
                left++;
            }
        }

        return minLen == INT_MAX? "" : s.substr(begin, minLen);
    }
};

int main(){
    Solution sol;
    string s = "wegdtzwabazduwwdysdetrrctotpcepalxdewzezbfewbabbseinxbqqplitpxtcwwhuyntbtzxwzyaufihclztckdwccpeyonumbpnuonsnnsjscrvpsqsftohvfnvtbphcgxyumqjzltspmphefzjypsvugqqjhzlnylhkdqmolggxvneaopadivzqnpzurmhpxqcaiqruwztroxtcnvhxqgndyozpcigzykbiaucyvwrjvknifufxducbkbsmlanllpunlyohwfsssiazeixhebipfcdqdrcqiwftutcrbxjthlulvttcvdtaiwqlnsdvqkrngvghupcbcwnaqiclnvnvtfihylcqwvderjllannflchdklqxidvbjdijrnbpkftbqgpttcagghkqucpcgmfrqqajdbynitrbzgwukyaqhmibpzfxmkoeaqnftnvegohfudbgbbyiqglhhqevcszdkokdbhjjvqqrvrxyvvgldtuljygmsircydhalrlgjeyfvxdstmfyhzjrxsfpcytabdcmwqvhuvmpssingpmnpvgmpletjzunewbamwiirwymqizwxlmojsbaehupiocnmenbcxjwujimthjtvvhenkettylcoppdveeycpuybekulvpgqzmgjrbdrmficwlxarxegrejvrejmvrfuenexojqdqyfmjeoacvjvzsrqycfuvmozzuypfpsvnzjxeazgvibubunzyuvugmvhguyojrlysvxwxxesfioiebidxdzfpumyon";
    string t = "ozgzyywxvtublcl";
    cout << sol.minWindow(s, t) <<endl;
    return 0;
}