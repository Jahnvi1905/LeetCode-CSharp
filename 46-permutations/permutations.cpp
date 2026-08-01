class Solution {
public:

    vector<vector<int>> ans;

    void solve(vector<int>& nums,
               vector<int>& curr,
               vector<int>& vis){

        if(curr.size()==nums.size()){

            ans.push_back(curr);

            return;
        }

        for(int i=0;i<nums.size();i++){

            if(vis[i])
                continue;

            vis[i]=1;

            curr.push_back(nums[i]);

            solve(nums,curr,vis);

            curr.pop_back();

            vis[i]=0;
        }
    }

    vector<vector<int>> permute(vector<int>& nums){

        vector<int> vis(nums.size(),0);

        vector<int> curr;

        solve(nums,curr,vis);

        return ans;
    }
};