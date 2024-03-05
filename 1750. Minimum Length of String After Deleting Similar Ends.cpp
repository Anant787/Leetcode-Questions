class Solution {
public:
    int minimumLength(string s) {
      int n=s.length(),i=0, j=n-1;

      if(n==1)
      {
          return 1;
      }

      char pre=s[0],suff=s[j];
      
      while(i<j)
      {
         if(s[i]==s[j])
         {
             pre=s[i];
             suff=s[j];
              i++;
              j--;
         }
         else if(s[i]==pre && s[i]==suff)
         {
             pre=s[i];
             i++;
         }
         else if(s[j]==suff && s[j]==pre)
         {
             suff=s[j];
             j--;
         }
         else
         break;
      } 
      if(i==j && s[i]==pre && s[j]==suff)
      return 0;
      return j-i+1; 
    }
};
