class Solution {
public:
    bool isSafe(char value, int row, int col, vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            if (board[i][col] == value) {
                return false;
            }
        }
        for (int j = 0; j < board.size(); j++) {
            if (board[row][j] == value) {
                return false;
            }
        }

        int boxRowStart = row - row % 3;
        int boxColStart = col - col % 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[boxRowStart + i][boxColStart + j] == value) {
                    return false;
                }
            }
        }

        return true;
    }
    bool solve(vector<vector<char>>& board) {
        int n = board.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') {
                    for (char val = '1'; val <= '9'; val++) {
                        if (isSafe(val, i, j, board)) {
                            board[i][j] = val;
                            bool solutionDePayoge = solve(board);
                            if (solutionDePayoge) {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) { solve(board); }
};
