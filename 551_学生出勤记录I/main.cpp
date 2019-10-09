// 一次遍历
// 时间复杂度O(n) 空间复杂度O(1)
class Solution {
public:
    bool checkRecord(string s) {
        int cntA = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == 'A')
                ++ cntA;
            if(cntA > 1 || ( i > 1 && s[i] =='L' && s[i-1] == 'L' && s[i-2] == 'L'))
                return false;
        }
        return true;
    }
};