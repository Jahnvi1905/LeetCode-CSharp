class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        // Step 1: Sort both arrays
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0; // child pointer
        int j = 0; // cookie pointer
        int satisfied = 0;

        while (i < g.size() && j < s.size()) {

            // Current cookie can satisfy current child
            if (s[j] >= g[i]) {
                satisfied++;
                i++;
                j++;
            }
            else {
                // Cookie is too small, try a bigger cookie
                j++;
            }
        }

        return satisfied;
    }
};