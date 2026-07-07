class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // dp[i] store karega index i tak ka maximum loota hua paisa
        vector<int> dp(n, 0);

        // Base Case 1: Agar sirf pehla ghar ho, toh use loat lo
        dp[0] = nums[0];

        // Base Case 2: Agar do ghar hain, toh dono mein se jo bada hai use looto
        dp[1] = max(nums[0], nums[1]);

        // Loop chalayenge baaki saare gharon ke liye (index 2 se n-1 tak)
        for (int i = 2; i < n; i++) {
            // Option 1: Current ghar looto (current paisa + i-2 tak ka max paisa)
            int pick = nums[i] + dp[i - 2];

            // Option 2: Current ghar chhod do (i-1 tak ka max paisa)
            int notPick = dp[i - 1];

            // Dono options mein se jo maximum hai, use dp[i] mein daal do
            dp[i] = max(pick, notPick);
        }

        // Aakhri ghar tak ka optimal answer dp[n-1] mein hoga
        return dp[n - 1];
    }
};
