class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end()); // 排序
        int len = timePoints.size();
        if(len < 1)
            return 0;
        auto minTime = getTimeAbs(timePoints[0], timePoints.back());// 最早和最晚的时间之差
        for(int i = 1; i < timePoints.size(); ++ i){
            minTime = min(minTime, getTimeAbs(timePoints[i], timePoints[i-1]));
        }
        return minTime;
    }
private:
    // 字符串转时间
    int str2time(string &s){
        return ((s[0] - '0') * 10 + s[1] - '0') * 60 +  (s[3] - '0') * 10 + (s[4] - '0') * 1;   // 转化为分钟
    }

    // 得到两个时间差值
    int getTimeAbs(string &s1, string&s2){
        auto t1 = str2time(s1);
        auto t2 = str2time(s2);
        auto t = abs(t1 - t2);
        return min(t, 24 * 60 - t); 
    }
};