class Solution {
public:
    string reverseWords(string s) {
        int l=0,r=0;
        while(l<s.size())
        {
            while(r<s.size()  && s[r] != ' ')
            {
                r++;
            }
            reverse(s.begin()+l,s.begin()+r);
            l=r+1;
            r=l;
        }
        return s;
        
        // int i=0;
        //     for(int j=0;i<s.size();j++)
        //     {
        //         if(s[i]=='')
        //         {
        //             reverse(s.begin()+i,s.end()+j);
        //             i=j+1;
        //             j=j+i;
        //         }
        //     }
        // return s;
    }
};