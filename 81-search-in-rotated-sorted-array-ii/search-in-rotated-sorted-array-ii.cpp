class Solution {
public:
    bool search(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;

        while(low <= high)
        {
            int mid = (low + high) / 2;

            // target found
            if(nums[mid] == target)
            {
                return true;
            }

            // duplicates
            if(nums[low] == nums[mid] && nums[mid] == nums[high])
            {
                low++;
                high--;
            }

            // left half sorted
            else if(nums[low] <= nums[mid])
            {
                if(target >= nums[low] && target < nums[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }

            // right half sorted
            else
            {
                if(target > nums[mid] && target <= nums[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }

        return false;
    }
};


// class Solution {
// public:
//     bool search(vector<int>& nums, int target) {

//         for(int i = 0; i < nums.size(); i++)
//         {
//             if(nums[i] == target)
//             {
//                 return true;
//             }
//         }

//         return false;
//     }
// };