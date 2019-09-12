/*
 * 用一个数组存储转化为k进制后每一位的值
 * 如果其余数字都出现k次，则这些数字%k为0，只剩下出现一次的数所对应的位
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<unsigned > h(32);    // 用unsigned防止溢出
        int k = 3;
        for(int i = 0; i < nums.size(); ++i)
            setKSystem(h, nums[i], k);
        int ret = getNumFromKSystem(h, k);  // 结果要转回int
        return ret;
    }
private:
    void setKSystem(vector<unsigned >& h, int val, int k){
        vector<unsigned> curKSystem = getKSystemFromNum(val, k);
        for (int i = 0; i < h.size(); ++i) {
            h[i] = (h[i] + curKSystem[i]) % k;  // 按位累加并对k求余
        }
    }

    vector<unsigned> getKSystemFromNum(unsigned val, int k){
        vector<unsigned> ret(32);
        int i = 0;
        while (val != 0){
            ret[i++] = val % k;
            val /= k;
        }
        return ret;
    }

    unsigned getNumFromKSystem(vector<unsigned> &h, int k){
        unsigned ret = 0;
        for (int i = h.size()-1; i >= 0; --i) {
            ret = ret * k + h[i];
        }
        return ret;
    }
};


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0, three = 0;
        for (int num : nums){
            two |= (one & num);     // two的相应的位等于1，表示该位出现2次
            one ^= num;             // one的相应的位等于1，表示该位出现1次
            three = (one & two);    // three的相应的位等于1，表示该位出现3次
            // 如果相应的位出现3次，则该位重置为0
            two &= ~three;
            one &= ~three;
        }
        return one;
    }
};