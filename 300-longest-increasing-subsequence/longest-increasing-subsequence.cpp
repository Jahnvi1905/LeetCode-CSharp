class Solution {
private:
    int solve(int ind, int prev_ind, vector<int>& nums, int n, vector<vector<int>>& dp) {
        // Base Case: Jab saare elements khatam ho jayein
        if (ind == n) return 0;
        
        // Memoization check: prev_ind ko +1 shift kiya hai coordinate change ke liye
        if (dp[ind][prev_ind + 1] != -1) return dp[ind][prev_ind + 1];
        
        // Option 1: Not Take (Element ko skip karo)
        int notTake = 0 + solve(ind + 1, prev_ind, nums, n, dp);
        
        // Option 2: Take (Sirf tabhi le sakte hain jab current element pichle element se bada ho)
        int take = 0;
        if (prev_ind == -1 || nums[ind] > nums[prev_ind]) {
            take = 1 + solve(ind + 1, ind, nums, n, dp);
        }
        
        // Dono options ka maximum return aur store karo
        return dp[ind][prev_ind + 1] = max(take, notTake);
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        // dp array size: [n][n + 1] kyunki prev_ind ki range -1 se n-1 tak jati hai.
        // Coordinate shift ke liye hum prev_ind ko +1 karke store karte hain.
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        
        // Pehle element (index 0) se start kiya, aur shuru me koi prev element nahi hai (-1)
        return solve(0, -1, nums, n, dp);
    }
};
