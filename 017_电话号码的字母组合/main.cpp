class Solution {
    unordered_map<char, string> table{
            {'0', " "}, {'1',"*"}, {'2', "abc"},
            {'3',"def"}, {'4',"ghi"}, {'5',"jkl"},
            {'6',"mno"}, {'7',"pqrs"},{'8',"tuv"},
            {'9',"wxyz"}};
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if(digits.empty()) return ret;
        helper(ret,"",digits,0);
        return ret;
    }

private:
    void helper(vector<string>& ret, string str, string &digits, int k){
        if(str.size() == digits.size()){
            ret.push_back(str);
            return;
        }

        string tmp = table[digits[k]];
        for (char c:tmp) {
            str += c;
            helper(ret, str, digits, k+1);
            str.pop_back();
        }
        return;
    }
};