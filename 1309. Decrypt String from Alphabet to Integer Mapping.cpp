class Solution {
public:
    string freqAlphabets(string s) {
        
        char c;
        string res = "";

        for(int i = s.length()-1;  i>=0;  i--){

            c = 96 + ( s[i]=='#' ? ((s[--i-1]-48)*10 + (s[i--]-48)) : (s[i]-48) );

            //(s[--i-1]-48)*10 subtracts the ASCII value of '0' from the first digit 
            //character, multiplies it by 10 to shift it to the tens place, and 
            //returns the result as an integer.

            res = c + res;        //reverse order maintain

        }
        return res;
        
        // int n = s.length(), i = 0;
        // string ans = "";
        // while(i < n)
        //     if(i + 2 < n && s[i + 2] == '#') {
        //         int ss = (s[i]-'0')*10 + (s[i+1]-'0');
        //         ans += char(ss+'a'-1);
        //         i += 3;
        //     }
        //     else {
        //         ans += char(s[i]-'0'-1+'a');
        //         i++;
        //     }
        // }
        // return ans;
        
    }
};
