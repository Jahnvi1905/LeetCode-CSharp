class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        vector<int> diff(1001,0);

        for(auto &t : trips){

            diff[t[1]] += t[0];
            diff[t[2]] -= t[0];
        }

        int passengers = 0;

        for(int x : diff){

            passengers += x;

            if(passengers > capacity)
                return false;
        }

        return true;
    }
};