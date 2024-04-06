class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st; // Stack to maintain valid parentheses
        int open = 0, close = 0; // Count of open and close parentheses

        // Iterate through each character in the string
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                open++; // Increment open count
                st.push(s[i]); // Push '(' to stack
            } else if (s[i] == ')') {
                close++; // Increment close count
                if (close <= open) {
                    st.push(s[i]); // Push ')' to stack if it's valid
                }
                if (close > open) {
                    close--; // Decrement close count if ')' is unmatched
                }
            } else {
                st.push(s[i]); // Push non-parentheses characters to stack
            }
        }

        string ans = ""; // Result string
        // Construct the result string by popping elements from the stack
        while (!st.empty()) {
            char ch = st.top();
            st.pop(); // Pop element from stack
            if (ch == '(' && open > close) {
                open--; // Decrement open count if '(' is unmatched
            } else {
                ans += ch; // Append character to result string
            }
        }

        reverse(ans.begin(), ans.end()); // Reverse the result string
        return ans; // Return the minimum removed valid string
    }
};
