class Solution {
public:
    int countDigitOne(int n) {
        if(n <1) return 0;
        int len = getLen(n);
        if(len == 1)
            return 1;   // 个位数出现1
        int tmp = (int)(pow(10, len-1));
        int first = n / tmp;                                 // 获取n的最高位数字
        int firstOneNum = first == 1 ? n % tmp + 1 : tmp;    // 首位出现1
        int otherOneNum = first * (len - 1) * (tmp / 10);    // 在介于n % tmp到n之间的数字中，除了最高位为1，其余各个数字分别为1 的总数和
        // 最高位的数字 x 除去最高位后剩下的位数 x 某一位固定是1的情况下，剩下的位数
        return firstOneNum + otherOneNum + countDigitOne(n%tmp);
    }
    
private:
    int getLen(int num){
        int len = 0;
        while(num!=0){
            ++ len;
            num /= 10;
        }
        return len;
    }
};