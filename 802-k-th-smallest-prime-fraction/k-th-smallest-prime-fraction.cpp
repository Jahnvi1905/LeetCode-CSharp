class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] * b[1] > b[0] * a[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        
        int n = arr.size();
        for (int i = 0; i < n - 1; ++i) {
            pq.push({arr[i], arr[n - 1], i, n - 1});
        }
        
        for (int _ = 0; _ < k - 1; ++_) {
            auto curr = pq.top();
            pq.pop();
            int i = curr[2];
            int j = curr[3];
            if (j - 1 > i) {
                pq.push({arr[i], arr[j - 1], i, j - 1});
            }
        }
        
        auto res = pq.top();
        return {res[0], res[1]};
    }
};
