class Solution {
private:
    bool isValid (vector<vector<char>>& board, int x, int y) {
        int flag[10] = {0};
        for (int i = 0; i < board.size(); ++i) {
            if (board[x][i] != '.') {                            //少了这句会导致这个判断总是false!!!
                if (flag[board[x][i] - '0'] == 1) {
                    return false;
                }
                else {
                    flag[board[x][i] - '0'] = 1;
                }
            }
        }
        memset(flag,0,sizeof(flag));
        for (int i = 0; i < board.size(); ++i) {
            if (board[i][y] != '.') {
                if (flag[board[i][y] - '0'] == 1) {
                    return false;
                }
                else {
                    flag[board[i][y] - '0'] = 1;
                }                
            }
        }
        memset(flag,0,sizeof(flag));
        int sqx = (x / 3) * 3;
        int sqy = (y / 3) * 3;
        for (int i = sqx; i < sqx + 3; ++i) {
            for (int j = sqy; j < sqy + 3; ++j) {
                if (board[i][j] != '.') {
                    if (flag[board[i][j] - '0'] == 1) {
                        return false;
                    }
                    else {
                        flag[board[i][j] - '0'] = 1;
                    }                    
                }
            }
        }
        return true;
    }
    bool solvehelper(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board.size(); ++j) {
                if (board[i][j] == '.') {
                    for (int k = 0; k < 9; ++k)  {
                        board[i][j] = '1' + k;
                        if (isValid(board, i, j)) {
                            if (solvehelper(board)) {
                                return true;
                            }
                        }
                    }
                    board[i][j] = '.';
                    return false;
                }
            }
        }
        return true;
    }   
public:
    void solveSudoku(vector<vector<char>>& board) {
        bool b = solvehelper(board);
    }
};