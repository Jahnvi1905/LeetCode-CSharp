#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
private:
    int solve(int r1, int c1, int r2, int n, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        // Calculate c2 using the step formula
        int c2 = r1 + c1 - r2;
        
        // 1. Out of Bounds or Thorn (-1) Check
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1) {
            return -1e9; // Return a large negative value to discard this invalid path
        }
        
        // 2. Base Case: Both robots reach the destination (n-1, n-1)
        if (r1 == n - 1 && c1 == n - 1) {
            return grid[r1][c1];
        }
        
        // 3. Memoization Check
        if (dp[r1][c1][r2] != -1) {
            return dp[r1][c1][r2];
        }
        
        // 4. Collect cherries from current cells
        int cherries = 0;
        if (r1 == r2 && c1 == c2) {
            cherries = grid[r1][c1]; // If both are on the same cell, collect once
        } else {
            cherries = grid[r1][c1] + grid[r2][c2]; // Collect from both distinct cells
        }
        
        // 5. Explore all 4 possible combinations of next moves:
        // Robot 1: Down, Robot 2: Down
        int dd = solve(r1 + 1, c1, r2 + 1, n, grid, dp);
        // Robot 1: Down, Robot 2: Right
        int dr = solve(r1 + 1, c1, r2, n, grid, dp);
        // Robot 1: Right, Robot 2: Down
        int rd = solve(r1, c1 + 1, r2 + 1, n, grid, dp);
        // Robot 1: Right, Robot 2: Right
        int rr = solve(r1, c1 + 1, r2, n, grid, dp);
        
        // Take the maximum of all valid paths
        cherries += max({dd, dr, rd, rr});
        
        // Store and return the result
        return dp[r1][c1][r2] = cherries;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Create a 3D DP vector initialized to -1
        // Dimensions: n x n x n
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
        
        // Start both robots from (0,0)
        int result = solve(0, 0, 0, n, grid, dp);
        
        // If no valid path is found, return 0 (as per the problem statement)
        return max(0, result);
    }
};
