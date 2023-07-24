class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
       
       int n = s.size();
       int lps[n+1];
       int i =0;
       int j =-1;
       lps[0]=-1;
       while(i<n)
       {

           while( j!= -1 && s[i] != s[j])
           {
               j = lps[j];
           }
           i++;
           j++;
           lps[i]=j;
       }
       for(auto x:lps)
       {
           cout<<x<<" ";
       }
      int period = n-lps[n];
       if(period != n && n% period == 0)return true;
       return false;


    }
};
