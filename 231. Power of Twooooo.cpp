class Solution {
public:
    bool isPowerOfTwo(int n) {
        //By bit manipulation method
        if(n<=0)
        {
            return false;
        }
        return ((n&(n-1))==0);


        //BY remainder Divident rule:: 


        // if(n==0)
        // {
        //     return false;
        // }
        // while(n%2==0)
        // {
        //     n=n/2;
        // }
        // return n==1;
        
    }
};
