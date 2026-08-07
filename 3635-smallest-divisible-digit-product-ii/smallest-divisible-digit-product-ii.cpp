#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Static DP table initialized globally once
static string dp[60][45];
static bool dp_initialized = false;

void initDPGlobal() {
    if (dp_initialized) return;
    
    for (int i = 0; i < 60; i++) {
        for (int j = 0; j < 45; j++) {
            dp[i][j] = string(100, '9');
        }
    }
    dp[0][0] = "";

    int digits[] = {2, 3, 4, 6, 8, 9};
    int f2[] = {1, 0, 2, 1, 3, 0};
    int f3[] = {0, 1, 0, 1, 0, 2};

    // Standard relaxation to precompute optimal combinations
    for (int step = 0; step < 60; step++) {
        for (int i = 55; i >= 0; i--) {
            for (int j = 40; j >= 0; j--) {
                if (dp[i][j].size() > 60) continue;
                for (int d = 0; d < 6; d++) {
                    int ni = min(55, i + f2[d]);
                    int nj = min(40, j + f3[d]);
                    string next_str = dp[i][j] + to_string(digits[d]);
                    sort(next_str.begin(), next_str.end());
                    
                    if (next_str.size() < dp[ni][nj].size()) {
                        dp[ni][nj] = next_str;
                    } else if (next_str.size() == dp[ni][nj].size() && next_str < dp[ni][nj]) {
                        dp[ni][nj] = next_str;
                    }
                }
            }
        }
    }
    dp_initialized = true;
}

class Solution {
private:
    string getMinSuffix(int c2, int c3, int c5, int c7) {
        string s = dp[min(55, c2)][min(40, c3)];
        if (c5 > 0) s.append(c5, '5');
        if (c7 > 0) s.append(c7, '7');
        sort(s.begin(), s.end());
        return s;
    }

public:
    string smallestNumber(string num, long long t) {
        // Runs in O(1) after the first testcase
        initDPGlobal();

        int t2 = 0, t3 = 0, t5 = 0, t7 = 0;
        while (t % 2 == 0) { t2++; t /= 2; }
        while (t % 3 == 0) { t3++; t /= 3; }
        while (t % 5 == 0) { t5++; t /= 5; }
        while (t % 7 == 0) { t7++; t /= 7; }
        if (t > 1) return "-1"; 

        int n = num.size();
        vector<int> p2(n + 1, 0), p3(n + 1, 0), p5(n + 1, 0), p7(n + 1, 0);
        int first_zero = -1;
        
        for (int i = 0; i < n; i++) {
            p2[i + 1] = p2[i]; p3[i + 1] = p3[i]; p5[i + 1] = p5[i]; p7[i + 1] = p7[i];
            if (num[i] == '0') {
                if (first_zero == -1) first_zero = i;
                continue;
            }
            int d = num[i] - '0';
            while (d % 2 == 0) { p2[i + 1]++; d /= 2; }
            while (d % 3 == 0) { p3[i + 1]++; d /= 3; }
            while (d % 5 == 0) { p5[i + 1]++; d /= 5; }
            while (d % 7 == 0) { p7[i + 1]++; d /= 7; }
        }

        if (first_zero == -1 && p2[n] >= t2 && p3[n] >= t3 && p5[n] >= t5 && p7[n] >= t7) {
            return num;
        }

        int limit = (first_zero != -1) ? first_zero : n - 1;
        for (int i = limit; i >= 0; i--) {
            int start_digit = num[i] - '0' + 1;
            for (int d = start_digit; d <= 9; d++) {
                int rem2 = max(0, t2 - p2[i]);
                int rem3 = max(0, t3 - p3[i]);
                int rem5 = max(0, t5 - p5[i]);
                int rem7 = max(0, t7 - p7[i]);

                int temp = d;
                while (temp % 2 == 0) { rem2 = max(0, rem2 - 1); temp /= 2; }
                while (temp % 3 == 0) { rem3 = max(0, rem3 - 1); temp /= 3; }
                while (temp % 5 == 0) { rem5 = max(0, rem5 - 1); temp /= 5; }
                while (temp % 7 == 0) { rem7 = max(0, rem7 - 1); temp /= 7; }

                string suffix = getMinSuffix(rem2, rem3, rem5, rem7);
                int rem_len = n - 1 - i;
                
                if (suffix.size() <= rem_len) {
                    string ans = num.substr(0, i) + to_string(d);
                    int ones = rem_len - suffix.size();
                    if (ones > 0) ans.append(ones, '1');
                    ans += suffix;
                    return ans;
                }
            }
        }

        string ans = getMinSuffix(t2, t3, t5, t7);
        int target_len = max((int)ans.size(), n + 1);
        string final_ans(target_len - ans.size(), '1');
        final_ans += ans;
        return final_ans;
    }
};
