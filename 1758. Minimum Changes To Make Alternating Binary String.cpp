class Solution {
public:
    int minOperations(string s) {
        int count1 = 0, count2 = 0;

        // take 010101
        for(int i = 0; i < s.length(); i+=2)
        {
            if(s[i] != '0') count1++;
            
            if(i+1 < s.length() && s[i+1] != '1') count1++;
            
            if(s[i] != '1') count2++;
            
            if(i+1 < s.length() && s[i+1] != '0') count2++;
        }
        return min(count1, count2);
    }
};
