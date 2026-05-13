// class Solution {
// public:
//     vector<int> findPeakGrid(vector<vector<int>>& mat) {

//         int n = mat.size();
//         int m = mat[0].size();

//         for(int i = 0; i < n; i++)
//         {
//             for(int j = 0; j < m; j++)
//             {
//                 int top = (i > 0) ? mat[i-1][j] : -1;
//                 int bottom = (i < n-1) ? mat[i+1][j] : -1;
//                 int left = (j > 0) ? mat[i][j-1] : -1;
//                 int right = (j < m-1) ? mat[i][j+1] : -1;

//                 if(mat[i][j] > top &&
//                    mat[i][j] > bottom &&
//                    mat[i][j] > left &&
//                    mat[i][j] > right)
//                 {
//                     return {i,j};
//                 }
//             }
//         }

//         return {-1,-1};
//     }
// };

class Solution {
public:

    int maxElementRow(vector<vector<int>>& mat, int col)
    {
        int n = mat.size();

        int maxVal = -1;
        int index = -1;

        for(int i = 0; i < n; i++)
        {
            if(mat[i][col] > maxVal)
            {
                maxVal = mat[i][col];
                index = i;
            }
        }

        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        int low = 0;
        int high = m - 1;

        while(low <= high)
        {
            int mid = (low + high) / 2;

            int row = maxElementRow(mat, mid);

            int left = (mid - 1 >= 0) ? mat[row][mid - 1] : -1;
            int right = (mid + 1 < m) ? mat[row][mid + 1] : -1;

            // peak found
            if(mat[row][mid] > left &&
               mat[row][mid] > right)
            {
                return {row, mid};
            }

            // move left
            else if(mat[row][mid] < left)
            {
                high = mid - 1;
            }

            // move right
            else
            {
                low = mid + 1;
            }
        }

        return {-1,-1};
    }
};