// class Solution {
// public:

//     bool possible(vector<int>& bloomDay, int day, int m, int k)
//     {
//         int count = 0;
//         int bouquets = 0;

//         for(int i = 0; i < bloomDay.size(); i++)
//         {
//             if(bloomDay[i] <= day)
//             {
//                 count++;
//             }
//             else
//             {
//                 bouquets += (count / k);
//                 count = 0;
//             }
//         }

//         bouquets += (count / k);

//         return bouquets >= m;
//     }

//     int minDays(vector<int>& bloomDay, int m, int k) {

//         long long val = 1LL * m * k;

//         if(val > bloomDay.size())
//         {
//             return -1;
//         }

//         int mini = *min_element(bloomDay.begin(), bloomDay.end());
//         int maxi = *max_element(bloomDay.begin(), bloomDay.end());

//         for(int day = mini; day <= maxi; day++)
//         {
//             if(possible(bloomDay, day, m, k))
//             {
//                 return day;
//             }
//         }

//         return -1;
//     }
// };

class Solution {
public:

    bool possible(vector<int>& bloomDay, int day, int m, int k)
    {
        int count = 0;
        int bouquets = 0;

        for(int i = 0; i < bloomDay.size(); i++)
        {
            if(bloomDay[i] <= day)
            {
                count++;
            }
            else
            {
                bouquets += (count / k);
                count = 0;
            }
        }

        bouquets += (count / k);

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        long long val = 1LL * m * k;

        if(val > bloomDay.size())
        {
            return -1;
        }

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;

        while(low <= high)
        {
            int mid = (low + high) / 2;

            if(possible(bloomDay, mid, m, k))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};
