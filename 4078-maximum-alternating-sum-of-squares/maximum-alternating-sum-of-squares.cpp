class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> squares(n);
        for (int i = 0; i < n; ++i) {
            squares[i] = (long long)nums[i] * nums[i];
        }
        sort(squares.begin(), squares.end());
        
        long long ans = 0;
        int mid = n / 2;
        for (int i = 0; i < mid; ++i) {
            ans -= squares[i];
        }
        for (int i = mid; i < n; ++i) {
            ans += squares[i];
        }
        return ans;
    }
};
