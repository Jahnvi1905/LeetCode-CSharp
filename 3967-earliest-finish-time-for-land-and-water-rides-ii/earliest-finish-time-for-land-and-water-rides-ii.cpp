class Solution {
public:
    long long solve(vector<int>& finishTime,
                    vector<int>& start,
                    vector<int>& duration) {

        int m = start.size();

        vector<pair<int,int>> rides;
        for(int i = 0; i < m; i++) {
            rides.push_back({start[i], duration[i]});
        }

        sort(rides.begin(), rides.end());

        vector<int> starts(m);
        vector<long long> prefMinDur(m);
        vector<long long> suffMinOpenFinish(m);

        for(int i = 0; i < m; i++) {
            starts[i] = rides[i].first;

            if(i == 0)
                prefMinDur[i] = rides[i].second;
            else
                prefMinDur[i] = min(prefMinDur[i - 1],
                                    (long long)rides[i].second);
        }

        for(int i = m - 1; i >= 0; i--) {
            long long val = (long long)rides[i].first + rides[i].second;

            if(i == m - 1)
                suffMinOpenFinish[i] = val;
            else
                suffMinOpenFinish[i] =
                    min(suffMinOpenFinish[i + 1], val);
        }

        long long ans = LLONG_MAX;

        for(int x : finishTime) {

            int idx = upper_bound(starts.begin(), starts.end(), x)
                      - starts.begin();

            if(idx > 0) {
                ans = min(ans,
                          (long long)x + prefMinDur[idx - 1]);
            }

            if(idx < m) {
                ans = min(ans,
                          suffMinOpenFinish[idx]);
            }
        }

        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int n = landStartTime.size();
        int m = waterStartTime.size();

        vector<int> landFinish(n);
        vector<int> waterFinish(m);

        for(int i = 0; i < n; i++) {
            landFinish[i] = landStartTime[i] + landDuration[i];
        }

        for(int i = 0; i < m; i++) {
            waterFinish[i] = waterStartTime[i] + waterDuration[i];
        }

        long long landToWater =
            solve(landFinish, waterStartTime, waterDuration);

        long long waterToLand =
            solve(waterFinish, landStartTime, landDuration);

        return (int)min(landToWater, waterToLand);
    }
};