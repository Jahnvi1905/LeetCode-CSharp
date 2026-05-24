class Solution {
public:

    bool isSafe(vector<vector<char>>& board,
                int row,
                int col,
                char num) {

        for(int i = 0; i < 9; i++) {

            // Row check
            if(board[row][i] == num)
                return false;

            // Column check
            if(board[i][col] == num)
                return false;

            // 3x3 box check
            if(board[3 * (row / 3) + i / 3]
                    [3 * (col / 3) + i % 3] == num)
                return false;
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {

        for(int row = 0; row < 9; row++) {

            for(int col = 0; col < 9; col++) {

                // Empty cell
                if(board[row][col] == '.') {

                    // Try numbers 1 to 9
                    for(char ch = '1'; ch <= '9'; ch++) {

                        if(isSafe(board, row, col, ch)) {

                            // Place number
                            board[row][col] = ch;

                            // Recursive call
                            if(solve(board))
                                return true;

                            // Backtrack
                            board[row][col] = '.';
                        }
                    }

                    // No valid number possible
                    return false;
                }
            }
        }

        // Sudoku solved
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {

        solve(board);
    }
};