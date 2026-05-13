class Solution {
public:
    int findMin(vector<int>& nums) {

        int low = 0;
        int high = nums.size() - 1;

        int ans = INT_MAX;

        while(low <= high)
        {
            // already sorted
            if(nums[low] <= nums[high])
            {
                ans = min(ans, nums[low]);
                break;
            }

            int mid = (low + high) / 2;

            // left half sorted
            if(nums[low] <= nums[mid])
            {
                ans = min(ans, nums[low]);
                low = mid + 1;
            }

            // right half sorted
            else
            {
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }

        return ans;
    }
};

// class Solution {
// public:
//     int findMin(vector<int>& nums) {

//         int mini = nums[0];

//         for(int i = 0; i < nums.size(); i++)
//         {
//             mini = min(mini, nums[i]);
//         }

//         return mini;
//     }
// };