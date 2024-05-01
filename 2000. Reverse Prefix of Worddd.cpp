class Solution {
public:
    string reverse(string &word,int l,int r)
    {
        while(l<r)
        {
            int temp = word[l];
            word[l] = word[r];
            word[r] = temp ; 
            l++;
            r--;
        }
        return word;
    }
    string reversePrefix(string word, char ch) {
        int index ;
        for(int i=0;i<word.size();i++)
        {
            if(word[i] == ch)
            {
                reverse(word,0,i);
                return word;
            }
        }
        return word;
        
    }
};
