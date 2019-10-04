// 排序+最小堆
// 时间复杂度：O(nlogn) 空间复杂度：O(n)
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.size() < 2) return intervals.size();
        multiset<int,less<int>> m;                  // 最小堆存每个会议室结束时间
        sort(intervals.begin(), intervals.end());   // 按开始时间排序
        m.insert(intervals[0][1]);
        for(int i = 1; i < intervals.size(); ++i){
            if(intervals[i][0] >= *m.begin())    // 如果开始时间比最小堆顶的元素大
                m.erase(m.begin());             // 即当前有会议室已结束
            m.insert(intervals[i][1]);
        }
        return m.size();
    }
};