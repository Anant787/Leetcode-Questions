class Solution {
public:
      bool chk(char c)      // check the vowel
      {
          if(c=='a' || c=='A') return true;
          if(c=='e' || c=='E') return true;
          if(c=='i' || c=='I') return true;
          if(c=='o' || c=='O') return true;
          if(c=='u' || c=='U') return true;
             return false;
      }
    string sortVowels(string s) {
         priority_queue<pair<int,char>> pq;    // heap
         for(auto x :s)
         {
              if(chk(x))
              {
                   pq.push({int(x*-1),x});
              }
         }
         for(int i = 0;i<s.length();i++)
         {
              char x = s[i];
             if(chk(x))
             {
                  auto tp = pq.top();
                  pq.pop();
                  s[i] = tp.second;
             }
         }
         return s;
    }
};
