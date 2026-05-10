class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();

        // dp[i] = maximum jumps needed to reach index i
        vector<int> dp(n, -1);

        dp[0] = 0;

        for(int i = 0; i < n; i++) {

            // if current index is reachable
            if(dp[i] == -1) continue;

            for(int j = i + 1; j < n; j++) {

                // check jump condition
                if(abs(nums[j] - nums[i]) <= target) {

                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }

        return dp[n - 1];
    }
};