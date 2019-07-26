class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int n = prices.size()  ;
        vector<int> sell(n, 0);     // sell[i]对应截止到第i天最后一个操作是卖出的最大利润
        vector<int> buy(n,0);       // buy[i]对应截止到第i天最后一个操作是买入的最大利润
        vector<int> cooldown(n,0);  // cooldown[i]对应截止到第i天最后一个操作是冷冻的最大利润
        buy[0] = -prices[0];
        for(int i = 1; i< n; ++i){
            sell[i] = max(sell[i-1], buy[i-1] + prices[i]);
            buy[i] = max(buy[i-1], cooldown[i-1] - prices[i]);
            cooldown[i] = max(cooldown[i-1], sell[i-1]);
        }
        return sell.back();
    }
};
