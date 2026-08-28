class Solution {
public:
    string convert(string s, int numRows) {
        // If there is only one row, no conversion is needed.
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        vector<string> rows(numRows);

        int currentRow = 0;
        int direction = 1;  // 1 = down, -1 = up

        for (char ch : s) {
            rows[currentRow] += ch;

            // Change direction at the top or bottom row
            if (currentRow == 0) {
                direction = 1;
            }
            else if (currentRow == numRows - 1) {
                direction = -1;
            }

            currentRow += direction;
        }

        // Combine all rows
        string ans;

        for (string &row : rows) {
            ans += row;
        }

        return ans;
    }
};