class Solution {
private:
    // Humne wahi purana LCS ka code use kiya hai
    int lcs(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }

public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end()); // String ko reverse kiya
        
        // s aur reversed string ka LCS hi hamara answer hai
        return lcs(s, t);
    }
};
