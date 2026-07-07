class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // 2D DP table: dp[i][j] store karega max strings jo hum pick kar sakte hain
        // jab hamare paas at most 'i' zeroes aur 'j' ones bache ho.
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Har ek string ko ek-ek karke process karenge
        for (const string& s : strs) {
            int zeros = 0, ones = 0;
            
            // Current string ke 0s aur 1s count karo
            for (char c : s) {
                if (c == '0') zeros++;
                else ones++;
            }

            // Reverse Loop chalana mandatory hai (m se lekar zeros tak, aur n se ones tak)
            // Taaki current string ka data usi loop mein dobara reuse na ho (0/1 Knapsack rule)
            for (int i = m; i >= zeros; i--) {
                for (int j = n; j >= ones; j--) {
                    // Option 1: Is string ko include karo -> 1 + dp[i - zeros][j - ones]
                    // Option 2: Is string ko skip karo -> dp[i][j]
                    dp[i][j] = max(dp[i][j], 1 + dp[i - zeros][j - ones]);
                }
            }
        }

        // Final answer matrix ke aakhri cell mein hoga jahan full capacity available thi
        return dp[m][n];
    }
};
