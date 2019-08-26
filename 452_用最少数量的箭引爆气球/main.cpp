// 贪心算法
bool cmp(const vector<int>& a, const vector<int>& b){
    return a[0]<b[0];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()) 
            return 0;
        sort(points.begin(), points.end(),cmp); // 按照区间起始点从小到大排序
        int begin = points[0][0];   // 该次射击的起始点
        int end = points[0][1];     // 该次射击范围的最小终止点
        int ret = 1;                // 最少射击次数
        for(int i = 1; i < points.size(); ++i){
            if(points[i][0] <= end){
                begin = points[i][0];
                end = min(end, points[i][1]);   // 更新终止点
            }
            else{
                ++ret;
                begin = points[i][0];
                end = points[i][1];
            }
        }
        return ret;
    }
};