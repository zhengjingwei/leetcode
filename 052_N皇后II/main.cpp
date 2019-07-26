class Solution {
public:
    int totalNQueens(int n) {
        if(n < 1) return 0;
        vector<int> record(n, 0);   // record[i]存储第i行放置Q的列号
        int ret = 0;
        dfs(record, 0, n, ret);
        return ret;
    }
    
private:
    void dfs(vector<int> &record, int row, int n, int &ret){
        if(row == n){
            ret ++;
            return;
        }

        for (int col = 0; col < n; ++col){
            if(isValid(record, row, col)){
                record[row] = col;
                dfs(record,row + 1, n, ret);
            }
        }
    }
    
    bool isValid(vector<int> &record, int row, int col){
        for (int i = 0; i< row; ++i){
            if(col == record[i] || abs(col - record[i]) == abs(row - i))
                return false;
        }
        return true;
    }
};