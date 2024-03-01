class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int one = 0 , n = s.length();

        for(int i = 0 ;i<n;i++)
        {
            if(s[i] == '1')
            {
                one++;     // count the number of 1;
            }
        }

        string ans = ""; // string to store the new maximum number

        if(one > 1)
        {
            one--;
            int i =0;
            while(one > 0)
            {
                ans += "1";
                i++;
                one--;
            }

            while(i<n-1)
            {
                ans += "0";
                i++;
            }
            ans += "1";
        }
        else
        {
            int i = 0;
            while( i < n-1)
            {
                ans += "0";
                i++;
            }
            ans += "1";
        }
        return ans;
        
    }
};
