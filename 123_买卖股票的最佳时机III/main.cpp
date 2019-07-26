/*
 * 动态规划一次遍历
 * 时间复杂度 O(n) 空间复杂度O(1)
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        vector<int> sell(2,0);
        vector<int> buy(2, INT_MIN);
        
        for(int p : prices){
            buy[0] = max(buy[0], -p);
            sell[0] = max(sell[0], buy[0] + p);
            buy[1] = max(buy[1], sell[0]-p);
            sell[1] = max(sell[1], buy[1] + p);
        }
        return sell[1];
    }
};