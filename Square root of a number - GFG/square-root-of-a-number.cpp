//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        if(x==0 || x==1)
        {
            return x;
        }
        long long int l =1 , r=x/2;
        long long int ans ;
        
        while(l<=r)
        {
           long long int mid = (l+r)/2;
            long long int sqr = mid*mid ;
            
            if(sqr == x)
            {
                return mid;
            }
            if(sqr<=x)
            {
                l = mid+1;
                ans = mid;
            }
            else
            {
                r = mid -1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends