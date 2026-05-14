class Solution {
public:
    bool rotateString(string s, string goal) {

        // length different hai to impossible
        if(s.length() != goal.length())
            return false;

        // s + s me goal present hona chahiye
        string temp = s + s;

        return temp.find(goal) != string::npos;
    }
};

// class Solution {
// public:
//     bool rotateString(string s, string goal) {

//         if(s.length() != goal.length())
//             return false;

//         // har rotation try karo
//         for(int i = 0; i < s.length(); i++)
//         {
//             // leftmost char ko end me bhejo
//             char first = s[0];
//             s.erase(0, 1);
//             s += first;

//             // match check karo
//             if(s == goal)
//                 return true;
//         }

//         return false;
//     }
// };