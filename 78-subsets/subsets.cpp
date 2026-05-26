class Solution {
public:

    void solve(int idx, vector<int>& nums,
               vector<int>& temp,
               vector<vector<int>>& ans)
    {
        // store current subset
        ans.push_back(temp);

        for(int i = idx; i < nums.size(); i++)
        {
            // take element
            temp.push_back(nums[i]);

            // recurse
            solve(i + 1, nums, temp, ans);

            // backtrack
            temp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> temp;

        solve(0, nums, temp, ans);

        return ans;
    }
};