class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        // Count the frequency of each bit across all numbers
        vector<int> bit_count(32, 0);
        for (int num : nums) {
            for (int i = 0; i < 30; ++i) {
                if ((num >> i) & 1) {
                    bit_count[i]++;
                }
            }
        }

        long long total_sum_of_squares = 0;
        long long MOD = 1e9 + 7;

        // Construct the k largest possible numbers
        for (int step = 0; step < k; ++step) {
            long long current_number = 0;
            for (int i = 0; i < 30; ++i) {
                if (bit_count[i] > 0) {
                    current_number |= (1LL << i);
                    bit_count[i]--;
                }
            }
            total_sum_of_squares = (total_sum_of_squares + (current_number * current_number) % MOD) % MOD;
        }

        return total_sum_of_squares;
    }
};
