class Solution {
public:
    // Set
    unordered_set<string> st; // unordered_set to store words from dict
    int n;
    int dp[51]; // store the min extra characters needed for each index

    int solve(string &s, int idx) {

        if (idx >= n) // base case
            return 0;

        if (dp[idx] != -1) return dp[idx]; 

        string currStr = ""; // store the current substr

        int minExtra = n; // initialize this to a maxvalue to find the min extra characters needed.

        for (int i = idx; i < s.size(); i++) {

            currStr.push_back(s[i]); // append characters to 'currStr' to form a substr

            int currExtra = (st.find(currStr) == st.end()) ? currStr.length() : 0; // extra char needed for the curr substr
            int nextExtra = solve(s, i + 1); // recursively calculate extra char for rest of the str
            int totalExtra = currExtra + nextExtra; // total extra char needed

            minExtra = min(minExtra, totalExtra); 
        }

        return dp[idx] = minExtra; 
    }

    int minExtraChar(string s, vector<string>& dictionary) {

        n = s.length();

        memset(dp, -1, sizeof(dp)); 

        for (string &word : dictionary) {
            st.insert(word); // insert words from the dict into unordered_set
        }

        return solve(s, 0); 
    }
};
