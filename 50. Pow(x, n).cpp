class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n;

        //for -ve values
        if(nn<0)
        {
            nn = -1 * nn;
        }

        while(nn)
        {
            if(nn%2 == 1)  //when power is odd
            {
                ans = ans * x;
                nn = nn-1;
            }
            else              //when power is even
            {
                x = x*x;
                nn = nn/2;
            }
        }

        if(n<0)  //for -ve values
        {
            ans = (double)1.0 / (double)ans;
        }

        return ans;
        
    }
};
