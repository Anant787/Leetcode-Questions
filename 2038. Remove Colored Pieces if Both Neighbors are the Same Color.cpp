class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size();
        int i = 0 , a=0,b=0;

        while(i<n)
        {
            int a1 = 0 , b1 = 0;

            while(i<n && colors[i] == 'A')      //count the number of A greater than 2 
            {
                a1++;
                i++;
            }
            while(i<n && colors[i] == 'B')  // count the number of B greater the 2
            {
                b1 ++ ;
                i++;
            }
            if(a1 > 2)
            {
                a += a1 - 2;    // count the number of A: alice can remove by  (n-2);
            }
            if(b1 > 2)
            {
                b += b1-2;     // count the number of B : bob can remove by (m-2);
            }
        }

        if(a > b)    // check the possibility
        {
            return true;   //alice Win  
        }
        if(a < b)
        {
            return false;  //bob win
        }
        return false;   //bob win
    }
};
