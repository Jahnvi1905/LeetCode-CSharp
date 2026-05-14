// class Solution {
// public:
//     bool isGood(vector<int>& nums) {

//         sort(nums.begin(), nums.end());

//         int n = nums.size();

//         // last element should appear twice
//         if(nums[n - 1] != nums[n - 2])
//             return false;

//         // check 1 to n-1
//         for(int i = 0; i < n - 1; i++)
//         {
//             if(nums[i] != i + 1)
//                 return false;
//         }

//         return true;
//     }
// };

class Solution {
public:
    bool isGood(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int n = nums.size();

        // maximum element
        int maxElement = nums[n - 1];

        // size should be maxElement + 1
        if(n != maxElement + 1)
            return false;

        // check 1 to maxElement-1
        for(int i = 0; i < n - 1; i++)
        {
            if(nums[i] != i + 1)
                return false;
        }

        // last element should also be maxElement
        return nums[n - 1] == maxElement;
    }
};