class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> v(n, string(n,'.'));
        vector<vector<string>> ret;
        dfs(v, 0, ret);
        return ret;
    }
    
private:
    bool isValid(vector<string> &v, int row, int col){
        bool valid = true;
        for(int i = 0; valid && i < row; i++)   // 检查该列
            valid = v[i][col]!= 'Q';
        // for(int i = 0; valid && i < col; i++)   // 检查该行 按行递归不需要检查行
        //     valid = v[row][i]!= 'Q';
        for(int i = row - 1 ,j = col-1; valid && i>=0 && j>=0;)
            valid = v[i--][j--]!= 'Q';              // 检查反对角线
        for(int i = row+-1, j = col+1; valid && i>=0 && j <v.size();)
            valid = v[i--][j++]!= 'Q';              // 检查对角线
        return valid;
    }
    
    // 按行递归
    void dfs(vector<string> &v, int row, vector<vector<string> > &ret){
        if(row == v.size()){
            ret.push_back(v);
            return;
        }
        for(int col = 0; col < v.size(); ++col){
            v[row][col] = 'Q';
            if(isValid(v, row, col))
                dfs(v, row + 1, ret);
            v[row][col] = '.';    // 回溯
        }
    }
};