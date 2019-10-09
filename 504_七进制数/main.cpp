class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0) return to_string(0);
        bool flag = num >= 0;
        num = num < 0 ? -num : num;
        string s;
        while(num > 0){
            s.push_back((char)(num % 7+'0'));
            num /= 7;
        }
        if(!flag) s.push_back('-');
        reverse(s.begin(), s.end());
        return s;
    }
};