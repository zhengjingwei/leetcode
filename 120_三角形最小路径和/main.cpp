// 动态规划 空间复杂度O(n^2)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int> (triangle.back().size(), INT_MIN));
        dp[0][0] = triangle[0][0];
        int ret = INT_MAX;
        if(triangle.size() == 1) return triangle[0][0];
        for (int i = 1; i < triangle.size(); ++ i){
            for(int j = 0; j < triangle[i].size(); ++j){
                int leftup = j > 0 ? dp[i-1][j-1] : INT_MAX;
                int rightup = j <  triangle[i].size() -1 ? dp[i-1][j] : INT_MAX;
                dp[i][j] = triangle[i][j] + min(leftup,rightup);
                if(i == triangle.size()-1)
                    ret = min(ret, dp[i][j]);
            }
        }
        
        return ret;
    }
};