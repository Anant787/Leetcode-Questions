class Solution {
public:
    int strStr(string haystack, string needle) {
       // return haystack.find(needle);       // buiild in function approach

       //simple iterative approach

       int m = haystack.size();
       int n = needle.size();

       for(int i=0;i<m-n+1;i++)
       {
           if(needle == haystack.substr(i,n))
           {
               return i;
           }
       }
       return -1;
    }
        
};
