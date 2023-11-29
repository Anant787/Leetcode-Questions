class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
       // int N=n.length();
        
        while(n!=0)
        {
            n=n & n-1;      // simple AND operator
            count++;         // increase the count
        }
        return count;     
        
        
    }
};
