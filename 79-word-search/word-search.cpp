class Solution {
public:

    bool solve(int row,
               int col,
               int index,
               vector<vector<char>>& board,
               string word) {

        // Word found
        if(index == word.size())
            return true;

        // Boundary conditions
        if(row < 0 || col < 0 ||
           row >= board.size() ||
           col >= board[0].size() ||
           board[row][col] != word[index]) {

            return false;
        }

        // Store current cell
        char ch = board[row][col];

        // Mark visited
        board[row][col] = '#';

        // Explore 4 directions
        bool found =
            solve(row + 1, col, index + 1, board, word) ||
            solve(row - 1, col, index + 1, board, word) ||
            solve(row, col + 1, index + 1, board, word) ||
            solve(row, col - 1, index + 1, board, word);

        // Backtrack
        board[row][col] = ch;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int rows = board.size();
        int cols = board[0].size();

        // Start from every cell
        for(int i = 0; i < rows; i++) {

            for(int j = 0; j < cols; j++) {

                if(solve(i, j, 0, board, word))
                    return true;
            }
        }

        return false;
    }
};