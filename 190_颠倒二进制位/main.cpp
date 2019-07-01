class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        int i = 32;
        while(i--){
            ret <<= 1;
            ret += n & (0x01); 
            n >>= 1;
        }
        return ret;
    }
};