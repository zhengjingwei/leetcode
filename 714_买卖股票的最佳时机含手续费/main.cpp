class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.empty()) return 0;
        int n = prices.size();
        vector<int> sell(n, 0); // sell[i]第i天截止最后一个操作是卖出的最大收益
        vector<int> buy(n, 0);  // buy[i]第i填截止最后一个操作是买入的最大收益
        buy[0] = -prices[0];
        for(int i = 1; i<n; ++i){
            buy[i] = max(buy[i-1], sell[i-1] - prices[i]);
            sell[i] = max(buy[i-1] + prices[i] - fee, sell[i-1]);
        }
        return sell.back();
    }
};