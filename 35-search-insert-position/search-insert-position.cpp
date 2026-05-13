class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int result = -1;
        for(int i =0 ;i<n;i++)
        {
            if(nums[i] == target)
            {
                result = i;
                break;
            }
            else if(nums[i]> target){
                result = i;
                break;
            }
            else{
                result = n;
            }
        }
        return result;
    }
};