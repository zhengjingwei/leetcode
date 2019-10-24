// 两个哈希表
// 时间复杂度：O(n) 空间复杂度：O(n)
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m;
        for(auto num : arr){
            m[num] += 1;
        }
        unordered_set<int> cnt;
        for(auto it = m.begin(); it != m.end(); ++ it){
            if(cnt.count(it->second) == 0)
                cnt.insert(it->second);
            else
                return false;
        }
        return true;
    }
};