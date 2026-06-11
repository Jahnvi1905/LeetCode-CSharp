class Solution {
public:
    int atMost(vector<int>& nums, int goal) {
        if (goal < 0) return 0;

        int left = 0;
        int sum = 0;
        int count = 0;

        for (int right = 0; right < nums.size(); right++) {
            sum = sum+ (nums[right] % 2);

            while (sum > goal) {
                sum = sum - (nums[left] % 2);
                left++;
            }

            count += (right - left + 1);
        }

        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};