class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> s;
        // 检查每一行
        for (int i = 0; i < board.size(); ++i) {
            s.clear();
            for (int j = 0; j < board[0].size(); ++j) {
                if(board[i][j] != '.'){
                    if(s.count(board[i][j]) == 0)
                        s.insert(board[i][j]);
                    else
                        return false;
                }
            }
        }
        // 检查每一列
        for (int j = 0; j < board[0].size(); ++j) {
            s.clear();
            for (int i = 0; i < board.size(); ++i) {
                if(board[i][j] != '.'){
                    if(s.count(board[i][j]) == 0)
                        s.insert(board[i][j]);
                    else
                        return false;
                }
            }
        }

        // 检查每个九宫格
        for (int k = 0; k < 9; ++k) {
            int x = k /3 * 3, y = (k %3) * 3;
            s.clear();
            for (int i = x; i < x+3; ++i) {
                for (int j = y; j < y+3; ++j) {
                    if(board[i][j] != '.'){
                        if(s.count(board[i][j]) == 0)
                            s.insert(board[i][j]);
                        else
                            return false;
                    }
                }
            }
        }
        return true;
    }
};