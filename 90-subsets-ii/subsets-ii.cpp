class Solution {
public:

    void solve(int index,
               vector<int>& nums,
               vector<int>& temp,
               vector<vector<int>>& ans) {

        // Store current subset
        ans.push_back(temp);

        for(int i = index; i < nums.size(); i++) {

            // Skip duplicates
            if(i > index && nums[i] == nums[i - 1])
                continue;

            // Take element
            temp.push_back(nums[i]);

            solve(i + 1, nums, temp, ans);

            // Backtrack
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> temp;

        // Important
        sort(nums.begin(), nums.end());

        solve(0, nums, temp, ans);

        return ans;
    }
};