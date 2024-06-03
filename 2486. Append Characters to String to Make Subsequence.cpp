class Solution {
public:
    int appendCharacters(string s, string t) {
        if (s == t) return 0; // If the strings are exactly the same, no characters need to be appended

        int le = 0;
        int re = 0;

        // Iterate through the characters in `s`
        while (le < s.size() && re < t.size()) {
            // If characters match, move to the next character in `t`
            if (s[le] == t[re]) {
                re++;
            }
            // Move to the next character in `s`
            le++;
        }

        // If re equals the length of t, all characters in t are found in s in order
        if (re == t.size()) {
            return 0;
        }

        // Calculate the number of characters to append
        return t.size() - re;
    }
};
