class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        // dp[i] stores the maximum relative score the current player can gain from index i
        vector<int> dp(n + 1, 0);
        
        // Traverse backwards from the last stone
        for (int i = n - 1; i >= 0; --i) {
            int take = 0;
            int max_score = INT_MIN;
            
            // A player can take 1, 2, or 3 stones
            for (int k = 1; k <= 3 && i + k <= n; ++k) {
                take += stoneValue[i + k - 1];
                // Current player's score minus the opponent's best score next turn
                max_score = max(max_score, take - dp[i + k]);
            }
            dp[i] = max_score;
        }
        
        // Alice starts at index 0
        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";
        return "Tie";
    }
};