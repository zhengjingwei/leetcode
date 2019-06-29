class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty() || intervals[0].empty()) return intervals;
        sort(intervals.begin(),intervals.end(), cmp);
        for (int i = intervals.size()-1; i >0 ; --i) {
            if(intervals[i-1][1]>= intervals[i][0]){
                intervals[i-1][1] = intervals[i][1];
                intervals[i-1][0] = min(intervals[i-1][0], intervals[i][0]);
                intervals.erase(intervals.begin()+i);
            }
        }
        return intervals;
    }

private:
    static bool cmp(const vector<int> &a, const vector<int> &b){
        if(a[1] == b[1])
            return a[0] < b[0];
        return a[1]<b[1];
    }
};