class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        /*** count-the-needed-to-delete-number ***/
        int left=0, right=0;    // 需要删除的左括号和右括号数量
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(') left++;
            else if(s[i]==')'){
                if(left>0) left--;
                else right++;
            }
        }

        vector<string> result;
        string cur;
        help(result, cur, s, 0, 0, left, right);
        return result;
        
    }
    // pair代表可行解中需要()的对数
    void help(vector<string> &result, string& cur, const string& s, int pos, int pair, int left, int right){
        if(pos==s.size()){
            if(pair==0 && left==0 && right==0)  result.push_back(cur);
            return;
        }
        if(s[pos] == '('){
            /*** skip ***/
            if(cur.back() != s[pos] && left > 0)
                help(result, cur, s, pos+1, pair, left-1, right);
            /*** keep ***/
            help(result, cur += s[pos], s, pos+1, pair+1, left, right);
            cur.pop_back();
        }
        else if(s[pos] == ')'){
            /*** skip ***/
            if(cur.back() != s[pos] && right > 0)
                help(result, cur, s, pos+1, pair, left, right-1);
            /*** keep ***/
            /*** bug-places : I forget to check whether pair > 0 ***/
            if(pair>0){
                help(result, cur += s[pos], s, pos+1, pair-1, left, right);
                cur.pop_back();
            }
        }
        else{
            help(result, cur += s[pos], s, pos+1, pair, left, right);
            cur.pop_back();
        }
    }
};