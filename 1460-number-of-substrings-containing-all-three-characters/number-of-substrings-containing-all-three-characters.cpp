class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> lastSeen(3, -1);
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            lastSeen[s[i] - 'a'] = i;

            ans += min({lastSeen[0], lastSeen[1], lastSeen[2]}) + 1;
        }

        return ans;
    }
};