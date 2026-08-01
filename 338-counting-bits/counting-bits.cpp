class Solution {
public:
    vector<int> countBits(int n) {
        // Create a vector of size n + 1 initialized to 0
        vector<int> ans(n + 1, 0);
        
        // Compute set bits for each number from 1 to n
        for (int i = 1; i <= n; i++) {
            // State transition: ans[i] = ans[i / 2] + (1 if i is odd else 0)
            ans[i] = ans[i >> 1] + (i & 1);
        }
        
        return ans; // Successfully returns the vector<int>
    }
};