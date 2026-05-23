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

        for(int i = index; i < candidates.size(); i++) {

            // Skip duplicates
            if(i > index && candidates[i] == candidates[i - 1])
                continue;

            // If element becomes greater than target
            if(candidates[i] > target)
                break;

            // Take element
            temp.push_back(candidates[i]);

            // Move to next index
            solve(i + 1, candidates,
                  target - candidates[i],
                  temp, ans);

            // Backtrack
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> temp;

        // Important
        sort(candidates.begin(), candidates.end());

        solve(0, candidates, target, temp, ans);

        return ans;
    }
};