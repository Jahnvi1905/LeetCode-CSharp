class Solution {
public:
    int numberOfSpecialChars(string word) {

        unordered_set<char> lower;
        unordered_set<char> upper;

        // lowercase aur uppercase store karo
        for(char ch : word)
        {
            if(islower(ch))
            {
                lower.insert(ch);
            }
            else
            {
                upper.insert(tolower(ch));
            }
        }

        int count = 0;

        // check karo dono me present hai ya nahi
        for(char ch : lower)
        {
            if(upper.count(ch))
            {
                count++;
            }
        }

        return count;
    }
};