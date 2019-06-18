class Solution {
public:
    string addStrings(string num1, string num2){
        string s;
        int carry = 0;
        for (int i = num1.size() -1, j = num2.size()-1; i>=0 || j>=0 || carry >0 ; --i, --j) {
            int x = i < 0 ? 0 : num1[i] - '0';
            int y = j < 0 ? 0 : num2[j] - '0';
            s.push_back((x+y+carry)%10 + '0');
            carry = (x+y+carry)/10;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};
