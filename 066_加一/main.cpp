class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int len = digits.size();
        for (int i = len-1; i >=0 ; --i) {
            digits[i] += carry;
            if(digits[i] >= 10){
                digits[i] -=10;
                carry = 1;
            } else
                carry = 0;
        }
        if(carry)
            digits.insert(digits.begin(), carry);
        return digits;
    }
};