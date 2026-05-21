// class Solution {
// public:
//     int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
//         int ans =0;
//         for(int i =0 ;i<arr1.size();i++){

//             for(int j= 0;j<arr2.size() ;j++){
//                 {
//                     string a = to_string(arr1[i]);
//                     string b = to_string(arr2[j]);

//                     int len = min(a.size(), b.size());

//                     int count = 0;
//                     for(int k=0 ;k<len ; k++)
//                     {
//                         if(a[k] == b[k])
//                         {
//                             count++;
//                         }
//                         else{
//                             break;
//                         }
//                     }

//                     ans= max(ans,count);
//                 }

//             }
//         }
//     return ans;
//     }
// };

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        unordered_set<int> st;

        // Store all prefixes of arr1
        for(int num : arr1)
        {
            while(num > 0)
            {
                st.insert(num);
                num /= 10;
            }
        }

        int ans = 0;

        // Check prefixes of arr2
        for(int num : arr2)
        {
            while(num > 0)
            {
                if(st.count(num))
                {
                    int len = to_string(num).size();

                    ans = max(ans, len);
                }

                num /= 10;
            }
        }

        return ans;
    }
};