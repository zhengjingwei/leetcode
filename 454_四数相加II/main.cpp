/* n为列表的平均长度
 * 时间复杂度O(n^2) 空间复杂度O(n)
 */
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int ret = 0;
        unordered_map<int,int> m;
        unordered_map<int,int>::iterator it1,it2;
        // 统计A+B的取值
        for(auto i:A)
            for(auto j:B)
                m[i+j] += 1;

        // 遍历C+D的取值，查看是否在哈希表中存在其相反数
        for(auto i:C)
            for(auto j:D)
                ret+=m[-(i+j)];

        return ret;
    }
};