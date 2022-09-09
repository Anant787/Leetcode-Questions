class Solution {
public:
    bool isPalindrome(int num) {
        
        string rev=to_string(num);
        reverse(rev.begin(),rev.end());
        return to_string(num)==rev;
        
//        long long int rev=0;
//         long int a=num;
//         if(num<=0)
//         {
//             return false;
//         }
        
//         while(num>0)
//         {
//             rev=(rev * 10)+( num % 10);
//             num=num/10;
//         }
        
//         if(rev == a)
//         {
//             return true;
//         }
//         else
//             return false;  
    }
};