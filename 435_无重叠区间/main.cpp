bool cmp(const vector<int>& a, const vector<int>& b){
    return a[0] < b[0];
}
// 贪心算法 O(nlogn) O(1)
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int end = intervals[0][1], prev = 0;
        int cnt = 0;
        for(int i = 1; i < intervals.size(); ++i){
            if(intervals[prev][1] > intervals[i][0]){     // 有重叠
                if(intervals[prev][1] > intervals[i][1])  // i被prev包围,将i作为新的prev
                    prev = i;                           // 否则将i作为去除的重叠区间，因为这样留给的后面的空间更大
                cnt ++;                                 
            }
            else{
                prev = i;
            }
        }
        
        return cnt;
    }
};

// 动态规划 O(n^2) O(n)
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        vector<int> dp(intervals.size(), 1);    // 以i元素为结尾，前i个元素最大不重叠区间数
        int maxNotOverlap = 1;
        for(int i = 1; i < intervals.size(); ++i){
            for(int j = i-1; j >=0; --j){
                if(intervals[i][0] >= intervals[j][1]){     // 如果无重叠
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            maxNotOverlap = max(maxNotOverlap, dp[i]);
        }
        return dp.size() - maxNotOverlap;
    }
};