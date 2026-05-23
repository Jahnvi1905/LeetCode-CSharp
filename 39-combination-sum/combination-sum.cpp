class Solution {
public:

    void solve(int index,
               vector<int>& candidates,
               int target,
               vector<int>& temp,
               vector<vector<int>>& ans) {

        // Base case
        if(target == 0) {
            ans.push_back(temp);
            return;
        }

        // If target becomes negative
        if(target < 0 || index == candidates.size()) {
            return;
        }

        // Take current element
        temp.push_back(candidates[index]);

        // Same index because element can be reused
        solve(index, candidates,
              target - candidates[index],
              temp, ans);

        // Backtrack
        temp.pop_back();

        // Do not take current element
        solve(index + 1, candidates,
              target, temp, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> temp;

        solve(0, candidates, target, temp, ans);

        return ans;
    }
};