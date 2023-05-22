class Solution {
public:
    int largestInteger(int num) {
        vector<int>v ; 
        
        while(num > 0)  //sepeate the element form the number
        {
            v.push_back(num%10);
            num /= 10;
        }

        reverse(v.begin(),v.end());  //reverse these element for exacr number
        int n = v.size();

        vector<int>even ;   //vector to distinguish between the parity
        vector<int>odd;
        
        for(int i=0;i<n;i++)
        { 
            if(v[i] % 2 == 0 )   //even elements are pushed into even vector
            {
                even.push_back(v[i]);
            }
            else                   //similary for odds
            {
                odd.push_back(v[i]);
            }
        }

        sort(even.begin(),even.end());   //sort the even and odd vector
        sort(odd.begin(),odd.end());

        int x = even.size() - 1;   //assign the last value of vector
        int y = odd.size() - 1;

        for(int i=0;i<n;i++)
        {
            if(v[i] % 2 == 0)   //swap the number by parity
            {
                v[i] = even[x];   //for even
                x--;
            }
            else
            {
                v[i] = odd[y];   //for odd
                y--;
            }
        }

        long long ans = 0 , fact = 1;

        for(int i = n-1 ; i>=0 ;i--)   //regenerate the number again
        {
            ans += (fact * v[i]);
            fact *= 10;
        }

        return ans;


    }
};
