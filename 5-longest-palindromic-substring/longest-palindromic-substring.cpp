// class Solution {
// public:

//     bool isPalindrome(string str)
//     {
//         int left = 0;
//         int right = str.length() - 1;

//         while(left < right)
//         {
//             if(str[left] != str[right])
//                 return false;

//             left++;
//             right--;
//         }

//         return true;
//     }

//     string longestPalindrome(string s) {

//         string ans = "";

//         for(int i = 0; i < s.length(); i++)
//         {
//             for(int j = i; j < s.length(); j++)
//             {
//                 string temp = s.substr(i, j - i + 1);

//                 if(isPalindrome(temp))
//                 {
//                     if(temp.length() > ans.length())
//                     {
//                         ans = temp;
//                     }
//                 }
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:

    string expand(string s, int left, int right)
    {
        while(left >= 0 && right < s.length() && s[left] == s[right])
        {
            left--;
            right++;
        }

        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {

        string ans = "";

        for(int i = 0; i < s.length(); i++)
        {
            // odd length palindrome
            string s1 = expand(s, i, i);

            // even length palindrome
            string s2 = expand(s, i, i + 1);

            if(s1.length() > ans.length())
                ans = s1;

            if(s2.length() > ans.length())
                ans = s2;
        }

        return ans;
    }
};