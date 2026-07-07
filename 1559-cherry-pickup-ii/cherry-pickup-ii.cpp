#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int solve(int i, int j, int k, int rows, int cols, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        // 1. Out of bounds check: If Robot 1 (j) or Robot 2 (k) goes outside the columns
        if (j < 0 || j >= cols || k < 0 || k >= cols) {
            return -1e8; // Return a large negative number to disregard this path
        }
        
        // 2. Base Case: If we reach the bottom-most row
        if (i == rows - 1) {
            if (j == k) return grid[i][j];    // If both robots land on the same cell, count cherries once
            else return grid[i][j] + grid[i][k]; // If they are on different cells, sum their cherries
        }
        
        // 3. Memoization Check: Return the result if it's already computed
        if (dp[i][j][k] != -1) {
            return dp[i][j][k];
        }
        
        int maxCherries = -1e8;
        
        // 4. Explore all 9 possible transition movements (3 options for Robot 1 * 3 options for Robot 2)
        for (int dj = -1; dj <= 1; dj++) {
            for (int dk = -1; dk <= 1; dk++) {
                
                int currentCherries = 0;
                // Add cherries from the current row cells
                if (j == k) {
                    currentCherries = grid[i][j]; // Overlap case
                } else {
                    currentCherries = grid[i][j] + grid[i][k];
                }
                
                // Recurse to the next row (i + 1) with updated column positions
                currentCherries += solve(i + 1, j + dj, k + dk, rows, cols, grid, dp);
                
                // Keep tracking the maximum cherries possible
                maxCherries = max(maxCherries, currentCherries);
            }
        }
        
        // Store the result in the 3D DP table and return
        return dp[i][j][k] = maxCherries;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Initialize a 3D DP table with dimensions: rows x cols x cols filled with -1
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(cols, -1)));
        
        // Robot 1 starts at column 0, Robot 2 starts at column (cols - 1) on row 0
        return solve(0, 0, cols - 1, rows, cols, grid, dp);
    }
};
