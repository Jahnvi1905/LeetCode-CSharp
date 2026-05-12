class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans;

        for(int i = 0; i < n; i++)
        {
            // Check both possible answers
            if(ans.size() == 0 || 
              (ans[0] != nums[i] && (ans.size() == 1 || ans[1] != nums[i])))
            {
                int count = 0;

                for(int j = 0; j < n; j++)
                {
                    if(nums[j] == nums[i])
                    {
                        count++;
                    }
                }

                if(count > n / 3)
                {
                    ans.push_back(nums[i]);
                }
            }
        }

        return ans;
    }
};