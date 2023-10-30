class Solution {
// Using comprator function 
    static int countBits(int a)
    {
        int count=0;      // to count the bits

        while(a != 0)
        {
            a = a & (a-1);    
            count++;
        }

        return count;
    }

    static bool compare(int a , int b)
    {
        int p = countBits(a);
        int q = countBits(b);

        if(p == q)    // check for if its bits are same
        {
            return a<=b;
        }
        else
        {
           return p<q;
        }
    }
    public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),compare);     // using compartor
        return arr;
    }
};
