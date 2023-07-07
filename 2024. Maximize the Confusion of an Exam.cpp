// class Solution {
// public:
//     int maxConsecutiveAnswers(string s, int k) {
//     int t = 0, f = 0;  // Count of 'T's and 'F's encountered so far
//     int j = 0;         // Pointer to the start of the window
//     int ans = 0;       // Maximum length of consecutive 'T's or 'F's

//     for (int i = 0; i < s.size(); i++) {
//         if (s[i] == 'T')
//             t++; // Increment 'T' count
//         else
//             f++; // Increment 'F' count

//         // Check if the count of 'T's or 'F's exceeds the constraint 'k'
//         while (t > k && f > k) s[j++]=='T' ? t--:f--;
//             // Move the window start 'j' forward and decrease the count of the corresponding character
            

//         // Update 'ans' with the maximum length of consecutive 'T's or 'F's encountered so far
//         ans = max(ans, t + f);
//     }

//     return ans; // Return the maximum length of consecutive 'T's or 'F's
// }
// };


//Sliding Window
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int i=0,j=0;
        int n=answerKey.length();
        unordered_map<char,int>m;
        int res=0;
        int mxFreq=0;
        while(j<n){
      m[answerKey[j]]++;
     
   mxFreq=max(mxFreq,m[answerKey[j]]);
      while((j-i+1)-(mxFreq)>k){
          m[answerKey[i]]--;
          if(m[answerKey[i]]==0) m.erase(m[answerKey[i]]);
          i++;
        }
        res=max(res,j-i+1);
        j++;

    }
    return res;
}
};
