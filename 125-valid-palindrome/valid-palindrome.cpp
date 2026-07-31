// class Solution {
// public:
//     bool isPalindrome(string s) {

//         string temp = "";

//         // lowercase + only alphanumeric
//         for(char ch : s) {
//             if(isalnum(ch)) {
//                 temp += tolower(ch);
//             }
//         }

//         int i = 0;
//         int j = temp.size() - 1;

//         while(i < j) {
//             if(temp[i] != temp[j]) {
//                 return false;
//             }

//             i++;
//             j--;
//         }

//         return true;
//     }
// };

class Solution {
public:
    bool isPalindrome(string s) {

        int l = 0;
        int r = s.size()-1;

        while(l<r){

            while(l<r && !isalnum(s[l])) l++;

            while(l<r && !isalnum(s[r])) r--;

            if(tolower(s[l])!=tolower(s[r]))
                return false;

            l++;
            r--;
        }

        return true;
    }
};