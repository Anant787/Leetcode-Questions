class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        if( n!=m)
        {
            return false;
        }
        
        //S1 and S2 is to store the frequency of each element
        //S4 and S4 is to store the element with their indexs for verifing from both strings

        vector<int>s1(26,0),s2(26,0),s3(26,0),s4(26,0);

        for(auto x : word1)
        {
            s1[x-'a']++;   //store the freq. of string 1  
            s3[x-'a']=1;    // mark the index of element as it it present in string
        }
        for(auto x : word2)
        {
            s2[x-'a']++;
            s4[x-'a']=1;
        }
        sort(s1.begin(),s1.end());   
        sort(s2.begin(),s2.end());

        return s1 == s2 && s3==s4;    //check the count of both freq. and index of element

    }
}; 
