// class Solution {
// public:
//     bool isPowerOfFour(int n) {
//         //  if(n==1) return 1;
//         // if(n<=0) return 0;
//         // while(n>1){
//         //     if(n%4!=0) return 0;
//         //     n/=4;
//         // }
//         // return 1;

//         if (n <= 0) return false; 
//         if ((n & (n - 1)) != 0) return false;
//         return (n - 1) % 3 == 0; 
        
        
//     }
// };

class Solution {
public:

    bool checkPowerOfFour(int n){
        //base case if n<4, if n<4 then check if it is one or not, if it is one then it is a power of 4 or else not
        if(n<4){
            if(n == 1)
            return true;
            return false;
        }

        if(n%4 == 0)
        return checkPowerOfFour(n/4);
        else
        return false;

    }

    bool isPowerOfFour(int n) {
        
        return checkPowerOfFour(n);

    }
};
