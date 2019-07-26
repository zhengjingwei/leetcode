class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k < 1 || prices.size() <= 1) return 0;
        if(k >= prices.size()/2) 
            return greedy(prices);
        vector<int> buy(k, INT_MIN);    // buy[i]和sell[i]分别表示截止到第i比交易买入和卖出时各自的最大收益
        vector<int> sell(k, 0);         // 实际交易笔数可能比i小     
        
        for(int p : prices){
            buy[0] = max(buy[0], -p);
            sell[0] = max(sell[0], buy[0] + p);    // 卖出第一笔
            for (int i = 1; i < k; ++ i){
                buy[i] = max(buy[i], sell[i-1] - p);
                sell[i] = max(sell[i], buy[i] + p);
            }
        }
        return sell.back();
    }
private:
    int greedy(vector<int>& prices){
        int ret = 0;
        for (int i = 1; i < prices.size(); ++i){
            if(prices[i] > prices[i-1])
                ret += prices[i] - prices[i-1];
        }
        return ret;
    }
};