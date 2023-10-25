class Solution {
public:
    int kthGrammar(int n, int k) {
        // Aditya verma approach

        if(n == 1 && k == 1)     // base condition 
        {
            return 0;
        }

        int mid = (pow(2,n-1)) / 2;   //find mid position (lenght / 2)

        // observation is that before the mid the element of N is same as N-1 row 
        if(k <= mid) 
        {
            return kthGrammar(n-1,k);
        }
        // here we observe,after the mid element of N is same as the complement of N-1 row
        else
        {
            return ! kthGrammar(n-1,k-mid);   // ! => Not    //Opposite condition
            
        }
        
    }
};
