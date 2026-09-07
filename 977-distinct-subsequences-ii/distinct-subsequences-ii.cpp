class Solution {
public:
    int distinctSubseqII(string s) {
        long long MOD = 1e9 + 7;
        std::vector<long long> dp(26, 0);
        
        for (char c : s) {
            long long total = 0;
            for (long long count : dp) {
                total = (total + count) % MOD;
            }
            // dp[c - 'a'] is updated to total + 1 (the new character itself)
            dp[c - 'a'] = (total + 1) % MOD;
        }
        
        long long ans = 0;
        for (long long count : dp) {
            ans = (ans + count) % MOD;
        }
        
        return ans;
    }
};