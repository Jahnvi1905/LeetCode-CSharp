class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();

        vector<vector<pair<int,int>>> adj(n);
        vector<int> indeg(n, 0);

        int high = 0;
        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            indeg[e[1]]++;
            high = max(high, e[2]);
        }

        // Topological sort
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) q.push(i);
        }

        vector<int> topo;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);

            for (auto &[v, c] : adj[u]) {
                if (--indeg[v] == 0)
                    q.push(v);
            }
        }

        auto possible = [&](int score) {
            const long long INF = 4e18;
            vector<long long> dist(n, INF);
            dist[0] = 0;

            for (int u : topo) {
                if (dist[u] == INF) continue;

                for (auto &[v, cost] : adj[u]) {
                    if (cost < score) continue;

                    // intermediate nodes must be online
                    if (v != n - 1 && !online[v]) continue;

                    if (dist[u] + cost < dist[v]) {
                        dist[v] = dist[u] + cost;
                    }
                }
            }

            return dist[n - 1] <= k;
        };

        int low = 0, ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};