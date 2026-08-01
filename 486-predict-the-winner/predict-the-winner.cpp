class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
         int n = nums.size();
        // dp[i][j] stores the maximum net score a player can get from nums[i...j]
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
        
        // Base case: Subarrays of length 1
        for (int i = 0; i < n; ++i) {
            dp[i][i] = nums[i];
        }
        
        // Build the table for subarrays of length 2 to n
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                dp[i][j] = std::max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }
        
        // If Player 1's score minus Player 2's score is >= 0, Player 1 wins
        return dp[0][n - 1] >= 0;
    }
};