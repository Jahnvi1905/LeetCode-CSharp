class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {

        vector<int> ans;

        for(int num : nums)
        {
            // number ko string me convert karo
            string s = to_string(num);

            // har character ko digit bana ke push karo
            for(char ch : s)
            {
                ans.push_back(ch - '0');
            }
        }

        return ans;
    }
};