//Solution1
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int flag[10] = {0};
        for (int i = 0; i < 9; ++i) {
            memset(flag,0,sizeof(flag));
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    if (flag[board[i][j] - '0'] == 1) {
                        return false;
                    }
                    else  {
                        flag[board[i][j] - '0'] = 1;
                    }
                }
            }
        }
        for (int i = 0; i < 9; ++i) {
            memset(flag,0,sizeof(flag));
            for (int j = 0; j < 9; ++j) {
                if (board[j][i] != '.') {
                    if (flag[board[j][i] - '0'] == 1) {
                        return false;
                    }
                    else  {
                        flag[board[j][i] - '0'] = 1;
                    }
                }
            }
        }
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                memset(flag,0,sizeof(flag));
                for (int m = 3 * i; m < 3 * i + 3; ++m) {
                    for (int n = 3 * j; n < 3 * j + 3; ++n) {
                        if (board[m][n] != '.') {
                            if (flag[board[m][n] - '0'] == 1) {
                                return false;
                            }
                            else  {
                                flag[board[m][n] - '0'] = 1;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};
//Solution2
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            int flag1[10] = {0};
            int flag2[10] = {0};
            int flag3[10] = {0};
            int m = (i / 3) * 3 , n = (i % 3) * 3;
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    if (flag1[board[i][j] - '0'] == 1) {
                        return false;
                    }
                    else  {
                        flag1[board[i][j] - '0'] = 1;
                    }
                }
                if (board[j][i] != '.') {
                    if (flag2[board[j][i] - '0'] == 1) {
                        return false;
                    }
                    else  {
                        flag2[board[j][i] - '0'] = 1;
                    }
                }
                int x = m + (j / 3);
                int y = n + (j % 3);
                if (board[x][y] != '.') {
                    if (flag3[board[x][y] - '0'] == 1) {
                        return false;
                    }
                    else  {
                        flag3[board[x][y] - '0'] = 1;
                    }
                }
            }
        }
        return true;
    }
};