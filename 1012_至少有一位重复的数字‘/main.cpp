// 排列组合题 比如N=1000 位数n=4
// 算四位数的所有不重复的数的数量
// 再减掉比N大的不重复的数的数量
// 时间复杂度：O(log10(N))跟N的位数有关
class Solution {
public:
    int numDupDigitsAtMostN(int N) {
        vector<int> nums;
        for(int x = N; x >0; x/=10)
            nums.push_back(x%10);
        reverse(nums.begin(), nums.end());    // 每一位上的数字用数组存储

        int nodup = 0, n = nums.size();
        // n位表示范围内无重复数字的排列数
        for(int i = 1; i <= n ; ++i){
            nodup += 9 * A(9, i-1);  //  9 * A(9, i-1)而不是A(9,i)原因：不允许前导0，但是后面的位可以有0
        }

        // 减去比N大的部分不重复数字数量
        unordered_set<int> dup;
        for (int i = 0; i < n; ++i){
            int a = nums[i];
            for(int j = a +1 ; j <= 9; ++j){
                if(dup.count(j) == 0)
                    nodup -= A(9 - dup.size(), n- i-1); // A(9-dup.size(), n-1 -i) -1是因为首位已经固定
            }
            if(dup.count(a))
                break;
            dup.insert(a);
        }
        return N - nodup;
    }
private:
    // 计算m个球中取n个球的排列A_m^n = m * (m-1) * ... * (m-(n-1))
    int A(int m, int n){
        return n == 0 ? 1: A(m, n-1) * (m - n +1);
    }
    // 迭代计算版本
    int A2(int m, int n){
        int ret = 1;
        for (int i = 0; i<n; ++i){
            ret *= m;
            --m;
        }
        return ret;
    }
};