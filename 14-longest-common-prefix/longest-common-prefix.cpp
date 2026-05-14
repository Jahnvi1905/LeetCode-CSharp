class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string ans = "";

        // first string ko base maan lo
        for(int i = 0; i < strs[0].length(); i++)
        {
            char ch = strs[0][i];

            // baki sab strings me check karo
            for(int j = 1; j < strs.size(); j++)
            {
                // agar length choti ho ya character same na ho
                if(i >= strs[j].length() || strs[j][i] != ch)
                {
                    return ans;
                }
            }

            ans += ch;
        }

        return ans;
    }
};