class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;          // 所有加油站的油量-消耗累积和
        int curr = 0;           // 当前油量
        int start = 0;          // 初始化从0号加油站开始
        for (int i = 0; i < gas.size(); ++i) {
            curr += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if(curr < 0){       // 无法到达下一个加油站
                curr = 0;       // 油量清空
                start = i+1;    // 将下一个加油站作为起点
            }
        }
        return total < 0?-1:start;
    }
};