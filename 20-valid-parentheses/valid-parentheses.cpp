class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;

        for(char ch : s) {

            // opening brackets
            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }

            // closing brackets
            else {

                // stack empty means invalid
                if(st.empty()) {
                    return false;
                }

                // matching brackets
                if((ch == ')' && st.top() == '(') ||
                   (ch == '}' && st.top() == '{') ||
                   (ch == ']' && st.top() == '[')) {

                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        // valid if stack becomes empty
        return st.empty();
    }
};