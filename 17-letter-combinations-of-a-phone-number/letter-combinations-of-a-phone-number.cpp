class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        // Simple mapping where index matches the digit
        vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        
        // Start with an empty string combination
        vector<string> result = {""}; 
        
        // Loop through each digit in the input
        for (char digit : digits) {
            vector<string> temp;
            string letters = mapping[digit - '0'];
            
            // Combine every existing combination with each new letter
            for (string combination : result) {
                for (char letter : letters) {
                    temp.push_back(combination + letter);
                }
            }
            // Update result for the next digit
            result = temp; 
        }
        
        return result;
    }
};
