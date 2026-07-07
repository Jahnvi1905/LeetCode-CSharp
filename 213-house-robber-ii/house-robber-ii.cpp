class Solution {
private:
    // Purana House Robber logic jo Kisi range ka max return karega
    int robLinear(vector<int>& nums, int start, int end) {
        int prev2 = 0;
        int prev1 = 0;

        for (int i = start; i <= end; i++) {
            int pick = nums[i] + prev2;
            int notPick = prev1;
            
            int current = max(pick, notPick);
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0]; // Sirf 1 ghar hai toh direct looto

        // Case 1: Pehla ghar looto, aakhri chhod do (0 se n-2)
        int ans1 = robLinear(nums, 0, n - 2);
        
        // Case 2: Pehla ghar chhod do, aakhri looto (1 se n-1)
        int ans2 = robLinear(nums, 1, n - 1);

        // Dono ka maximum hamara final answer hoga
        return max(ans1, ans2);
    }
};
