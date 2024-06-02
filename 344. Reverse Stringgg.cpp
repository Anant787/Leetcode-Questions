 class Solution {
public:
    void reverseString(vector<char>& s) {
//         int n=s.size();
//         int st=0,e=n-1;
        
//         while(st<e)
//         {
//             // char temp=s[st];
//             // s[st]=s[e];
//             // s[e]=temp;
//             swap(s[st],s[e]);
//             st++;
//             e--;
//         }
        reverse(s.begin(),s.end());
    }
};
