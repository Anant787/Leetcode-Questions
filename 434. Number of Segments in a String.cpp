class Solution {
public:
    int countSegments(string s) {
        int count = 0 ;   //to count the number of segments
        int n = s.size();
        int i =0 ;

        while(i<n)
        {
            if(s[i] == ' ')
            {
                i++;
            }
            else
            {
                count++;   //increase the count
                while(i<n && s[i] != ' ')
                {
                    i++;
                }
            }
        }
        return count;    //return the answer
        
    }
};
