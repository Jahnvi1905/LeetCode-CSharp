class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());

        int n = nums.size();

        int closest = nums[0] + nums[1] + nums[2];

        for(int i =0;i<n-2;i++){
            int left = i+1;
            int right = n-1;

            while(left<right){

                int sum = nums[i]+ nums[left] + nums[right];

                if(abs(sum-target) < abs(closest-target)){
                    closest = sum;
                }
                 // Exact match
                if (sum == target) {
                    return sum;
                }

                // Sum is too small → increase it
                if (sum < target) {
                    left++;
                }

                // Sum is too large → decrease it
                else {
                    right--;
                }

            }
        }

        return closest;
    }
};