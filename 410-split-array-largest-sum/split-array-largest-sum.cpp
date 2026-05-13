// class Solution {
// public:

//     int countSubarrays(vector<int>& nums, int maxSum)
//     {
//         int subarrays = 1;
//         long long sum = 0;

//         for(int i = 0; i < nums.size(); i++)
//         {
//             if(sum + nums[i] <= maxSum)
//             {
//                 sum += nums[i];
//             }
//             else
//             {
//                 subarrays++;
//                 sum = nums[i];
//             }
//         }

//         return subarrays;
//     }

//     int splitArray(vector<int>& nums, int k) {

//         int low = *max_element(nums.begin(), nums.end());

//         int high = accumulate(nums.begin(), nums.end(), 0);

//         for(int maxSum = low; maxSum <= high; maxSum++)
//         {
//             int parts = countSubarrays(nums, maxSum);

//             if(parts <= k)
//             {
//                 return maxSum;
//             }
//         }

//         return -1;
//     }
// };

class Solution {
public:

    int countSubarrays(vector<int>& nums, int maxSum)
    {
        int subarrays = 1;
        long long sum = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(sum + nums[i] <= maxSum)
            {
                sum += nums[i];
            }
            else
            {
                subarrays++;
                sum = nums[i];
            }
        }

        return subarrays;
    }

    int splitArray(vector<int>& nums, int k) {

        int low = *max_element(nums.begin(), nums.end());

        int high = accumulate(nums.begin(), nums.end(), 0);

        int ans = high;

        while(low <= high)
        {
            int mid = (low + high) / 2;

            int parts = countSubarrays(nums, mid);

            if(parts <= k)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};