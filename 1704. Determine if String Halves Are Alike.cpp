class Solution {

    //Function for identifing the vowels
    
    bool isVowel(char c)
    {
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ||c=='A' || c=='E' ||c=='I' ||c=='O' ||c=='U')
        {
            return true;
        }
        return false;
    }
public:
    bool halvesAreAlike(string s) {
        int l =s.size(); 
         //count1 is used to count the vowel of first half
        //count1 is used to count the vowel of second half
        int count1 = 0,count2 = 0;
        
        for(int i =0;i<l/2;i++)
        {
            if(isVowel(s[i]))    //if vowel present in first half then add to the count1
            {
                count1++;
            }
        }
        for(int i =l/2;i<l;i++) //if vowel present in second half 
        {
            if(isVowel(s[i]))
            {
                count2++;
            }
        }

        return count1 == count2;  //return true if the count is Equal 

        
    }
};
