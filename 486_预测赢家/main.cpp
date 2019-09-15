/*
 * 给定一个表示分数的非负整数数组。 玩家1从数组任意一端拿取一个分数，随后玩家2继续从剩余数组任意一端拿取分数，然后玩家1拿，……。
 * 每次一个玩家只能拿取一个分数，分数被拿取之后不再可取。
 * 直到没有剩余分数可取时游戏结束。最终获得分数总和最多的玩家获胜。
 * 
 * 动态规划
 * 时间复杂度O(n^2) 空间复杂度O(n^2)
 */
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        if(nums.size() == 1)
            return true;
        int n = nums.size();
        vector<vector<int>> f(n, vector<int>(n,0)); // nums[i..j]作为先手拿的最大收益
        vector<vector<int>> s(n, vector<int>(n,0)); // nums[i..j]作为后手拿的最大收益
        // 由状态方程确定变量i,j的更新顺序
        for (int j = 0; j < n; ++j) {
            f[j][j] = nums[j];  // 最后剩一个必然是先手拿走
            for (int i = j-1; i >= 0 ; --i) {
                f[i][j] = max(nums[i] + s[i+1][j], nums[j] + s[i][j-1]);
                s[i][j] = min(f[i+1][j], f[i][j-1]);    // 对手会把最差情况留给玩家
            }
        }
        return f[0][n-1] >= s[0][n-1];
    }
};