class Solution {
public:
    void sortColors(vector<int>& nums) {
        // int n = nums.size();
        // for(int i= 0;i<n ; i++)
        // {
        //     for(int j=i+1;j<n ; j++)
        //     {
        //         if(nums[j]<nums[i])
        //             swap(nums[i],nums[j]);
        //     }
        // }
        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0)
                swap(nums[low++], nums[mid++]);
            else if (nums[mid] == 1)
                mid++;
            else
                swap(nums[mid], nums[high--]);
        }
    }
};