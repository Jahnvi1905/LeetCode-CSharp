/*
Approach:
1. Traverse each layer separately.
2. Store layer elements in a 1D vector.
3. Rotate vector by k positions.
4. Put rotated values back into matrix.
*/

class Solution {
public:
    
    void rotate(vector<int>& arr, int k) {
        int n = arr.size();
        k = k % n;

        vector<int> temp(n);

        for(int i = 0; i < n; i++) {
            temp[i] = arr[(i + k) % n];
        }

        arr = temp;
    }

    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        int layers = min(m, n) / 2;

        for(int layer = 0; layer < layers; layer++) {

            vector<int> elements;

            int top = layer;
            int left = layer;
            int bottom = m - layer - 1;
            int right = n - layer - 1;

            // Top row
            for(int j = left; j <= right; j++)
                elements.push_back(grid[top][j]);

            // Right column
            for(int i = top + 1; i <= bottom - 1; i++)
                elements.push_back(grid[i][right]);

            // Bottom row
            for(int j = right; j >= left; j--)
                elements.push_back(grid[bottom][j]);

            // Left column
            for(int i = bottom - 1; i >= top + 1; i--)
                elements.push_back(grid[i][left]);

            // Rotate layer
            rotate(elements, k);

            int idx = 0;

            // Put back Top row
            for(int j = left; j <= right; j++)
                grid[top][j] = elements[idx++];

            // Put back Right column
            for(int i = top + 1; i <= bottom - 1; i++)
                grid[i][right] = elements[idx++];

            // Put back Bottom row
            for(int j = right; j >= left; j--)
                grid[bottom][j] = elements[idx++];

            // Put back Left column
            for(int i = bottom - 1; i >= top + 1; i--)
                grid[i][left] = elements[idx++];
        }

        return grid;
    }
};