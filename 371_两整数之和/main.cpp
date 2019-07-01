class Solution {
public:
    int getSum(int a, int b) {
       return b == 0?a:getSum(a^b, ((unsigned int) (a&b)) << 1); // 防止 AddressSanitizer 对有符号左移的溢出保护处理
    }
};