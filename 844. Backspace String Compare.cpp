class Solution {
public:
    bool backspaceCompare(string s, string t) {
        //Stirng approach 
        // int i = s.length() - 1;
        // int j = t.length() - 1;
        // int skipS = 0, skipT = 0;

        // while (i >= 0 || j >= 0) {
        //     // Find the next character in s that is not backspace.
        //     while (i >= 0) {
        //         if (s[i] == '#') {
        //             skipS++;
        //             i--;
        //         } else if (skipS > 0) {
        //             skipS--;
        //             i--;
        //         } else {
        //             break;
        //         }
        //     }
            
        //     // Find the next character in t that is not backspace.
        //     while (j >= 0) {
        //         if (t[j] == '#') {
        //             skipT++;
        //             j--;
        //         } else if (skipT > 0) {
        //             skipT--;
        //             j--;
        //         } else {
        //             break;
        //         }
        //     }
            
        //     // If the current characters in s and t are different, return false.
        //     if ((i >= 0 && j >= 0) && (s[i] != t[j])) {
        //         return false;
        //     }
            
        //     // If one string has reached its end but the other hasn't, return false.
        //     if ((i >= 0) != (j >= 0)) {
        //         return false;
        //     }

        //     i--;
        //     j--;
        // }

        // return true;

        // Stack approach
        stack<char>s1,s2;
        for(int i=0;i<s.length();i++){
            if(s[i]=='#'){
                if(!s1.empty()){
                    s1.pop();
                }
            }
            else{
                s1.push(s[i]);
            }
        }
        for(int i=0;i<t.length();i++){
            if(t[i]=='#'){
                if(!s2.empty()){
                    s2.pop();
                }
            }
            else{
                s2.push(t[i]);
            }
        }
        if(s1==s2){
            return 1;
        }
        return 0;
    }
};
