/*
 * 贪心两次遍历O(n)
 */
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> ret;
        unordered_map<char, int> m;
        for (int i = 0; i < S.size(); ++i)
            m[S[i]] = i;
        int maxPos = m[S[0]];   // 当前最远距离
        int begin = 0;          // 起始点
        for (int i = 0; i < S.size(); ++i) {
            if(m[S[i]] > maxPos)
                maxPos = m[S[i]];   
            if(i == maxPos){
                ret.push_back(maxPos+1 - begin);
                begin = i+1;
            }
        }
        return ret;
    }
};