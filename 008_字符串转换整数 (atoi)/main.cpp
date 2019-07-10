class Solution {
public:
    int myAtoi(string str) {
        if(str.empty()) return 0;
        int ret = 0, i = 0;
        bool pos = true;
        while (i <str.size() && str[i] == ' ') ++i;
        if(i>=str.size()) return 0;
        if(str[i] == '+' || str[i] == '-'){
            pos = str[i++] == '+'? true: false;
        }

        while (i < str.size()){
            if(str[i] < '0' || str[i] > '9')
                break;
            if(ret < INT_MIN /10 || (ret == INT_MIN/10 && str[i] - '0' >=8))
                return pos?INT_MAX:INT_MIN;
            ret = ret * 10 - (str[i] - '0');
            ++i;
        }
        return pos? -ret : ret;
    }
};