//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
   public:
    int findSum(int A[], int N)
    {
    // 	sort(A,A+N);
    // 	int ans =0;
    // 	ans  = A[0] + A[N-1];
    // 	return ans;
    
        int max,min;
        if(N==1)
        {
            max = A[0];
            min = A[0];
        }
        else
        {
            if(A[0]>A[1])
            {
                max = A[0];
                min = A[1];
            }
            else
            {
                max = A[1];
                min = A[0];
            }
            
            for(int i =2;i<N;i++)
            {
                if(A[i]>max)
                {
                    max = A[i];
                }
                if(A[i]<min)
                {
                    min = A[i];
                }
                // cout<<max<<" ";
                // cout<<min << " ";
            }
        }
        return max+min;
    }

};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	      cin>>arr[i];
	    Solution ob;  
	    int ans=ob.findSum(arr, n);
	    cout<<ans;
	    cout<<"\n";
	}
	return 0;
}

// } Driver Code Ends