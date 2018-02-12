class Solution {
public:
    int myAtoi(string str) {
        int ret = 0,i=0;
        char sign = '+';    
        while(str[i]==' ') ++i;
        if(str[i]=='+'||str[i]== '-'){ // if string has sign
            if((str[i]=='+'&&str[i+1]=='-') || (str[i]=='-'&&str[i+1]=='+')) // 2 sign
            return 0;
            sign = str[i]; // get the sign
            ++i;
        }
        while(i < str.size()){
            if(str[i]> '9' || str[i] <'0')
                break;
            if(ret >INT_MAX/10 || (ret == INT_MAX/10 && str[i]-'0' >7)){ // if overflow
                if(sign =='+') return INT_MAX;
                else if(sign = '-') return INT_MIN;
            }
            ret = ret * 10 + (str[i] -'0');
            ++i;
        }
        if(sign == '-') ret = -ret;
        return ret;
    }
};