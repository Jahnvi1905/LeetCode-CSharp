// class Solution {
// public:
//     string frequencySort(string s) {

//         int n = s.length();

//         for(int i = 0; i < n; i++)
//         {
//             for(int j = i + 1; j < n; j++)
//             {
//                 int count1 = 0;
//                 int count2 = 0;

//                 // frequency of s[i]
//                 for(int k = 0; k < n; k++)
//                 {
//                     if(s[k] == s[i])
//                         count1++;
//                 }

//                 // frequency of s[j]
//                 for(int k = 0; k < n; k++)
//                 {
//                     if(s[k] == s[j])
//                         count2++;
//                 }

//                 // higher frequency ko aage lao
//                 if(count2 > count1)
//                 {
//                     swap(s[i], s[j]);
//                 }
//             }
//         }

//         // same characters ko together lane ke liye
//         string ans = "";

//         vector<int> visited(128, 0);

//         for(int i = 0; i < n; i++)
//         {
//             if(visited[s[i]] == 0)
//             {
//                 for(int j = i; j < n; j++)
//                 {
//                     if(s[j] == s[i])
//                     {
//                         ans += s[j];
//                     }
//                 }

//                 visited[s[i]] = 1;
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:

    static bool cmp(pair<char,int> a, pair<char,int> b)
    {
        return a.second > b.second;
    }

    string frequencySort(string s) {

        unordered_map<char,int> mp;

        // frequency count
        for(char ch : s)
        {
            mp[ch]++;
        }

        vector<pair<char,int>> v(mp.begin(), mp.end());

        // frequency ke basis pe sort
        sort(v.begin(), v.end(), cmp);

        string ans = "";

        // character ko frequency times add karo
        for(auto it : v)
        {
            ans += string(it.second, it.first);
        }

        return ans;
    }
};